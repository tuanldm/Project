----------------------------------------------------------------------------------------------------------------------------------------------------
- MCU_STM32F411E_AudioProject:
	Requirement				
		1. Use the STM32F4 discovery board				
		2. Module hardware use in the project				
		- UART			-> print the log while running			
		- BUTTON		-> play/stop the music, skip/pause the song			
		- LED			-> show the status of playing song. status program			
		- AUDIO			-> output the audio			
		- USB OTG		-> read the song			
		- Motion sensor	-> change the volume			
		3. Use the IDE KEIL C and the peripheral standard library				
		4. The project use the RTOS to implement							
					
	User story				
		1. At the startup 2s:				
			- Blink all the LED every 0.2s				
			- Send the message to PC "Startup state"				
			- Read the data from motion sensor				
			- Read the data from USB				
			- Send the initial sound to audio				
		2. Running state:				
			- Press the Button one time for start/stop				
			- Press the button twice to skip the song				
			- Press the button 3 times to pause the song				
			- Hold the button for 3s to reject the USB				
		3. The motion sensor for increase/decrease the volume				
			- the Y axis is for incease/decrease the volume				
			- The X axis (shaking) for next/previous song				
			- The Z axis is for running the song faster/normal				
			4. The log file will be written into the USB as file log				
		5. The LED is blink while running				
			- 1s if doesnt play any song				
			- 0.5s if playing the song				
		6. Audio				
			- if the USB doesnt plug in, and button press, the audio "the USB doesnt plug" is speak				
			- Output the audio from USB				
			- Speak the sound Beep when button press
	
	Role:
		LyNC: 
			- Setup Standard Library for STM32F411E
			- Setup GPIO Led, Button
			- Setup SPI Motion Sensor
		ChungVB:
			- Setup I2S Audio
			- Setup FreeRTOS
		TaiNT:
			- Setup USB (Not finish)
		TuanLDM: (It's me)
			- Setup USART
				+ Init USART
				+ Send String Data to Hercules
			- Responsible for coding following requirement based on module which was Setup by colleagues
				+ Initial Module
				+ Task 0: Initial_Start
					. Initial sound to audio
					. Send the message to PC "Startup state" (PC -> Using Hercules software)				
					. Read the data from motion sensor				
					. Read the data from USB
					. Blink all the LED every 0.2s
				+ Task 1: Using Led to display actions
					. (Start == 1) && (Pause == 0) -> Blink led every 0.5s
					. (Start == 1) && (Pause == 1) -> Blink led every 1.0s
				+ Task 2: Get data from Motion Sensor
					. At a time, only one signal X or Y or Z with the largest change is received
					. Once the signal is received, it will be temporarily locked for 2.0s. After this time, the signal can be received again
				+ Task 3: USB
					(Wait USB_Module to Read)
				
				+ Task 4: Get signal from Button
					. Press a time: 	start/stop				-> Enable/Disable Audio. When Start, USB is read in begin
					. Press 2 times:	skip the song			-> Skip +5s
					. Press 3 times: 	pause the song			-> Pause reading USB
					. Hold 3s: 			reject the USB			-> Commonly, RejectUSB_bit = 0. When we plug USB, StateUSB_bit = 1. When RejectUSB_bit = 1, USB will not read until 
																		we plug	USB again (StateUSB_bit = 0 then allow to reset RejectUSB_bit = 0)
					-> Interval of 2 times of press is 0.7s
				+ Task 5: Audio
					(Wait USB_Module to Read and Sound)
				
				+ Task 6: Alarm
					. Speak the sound "Beep" when button press	(timeButton < 3000);
					. if the USB doesnt plug in, and button press, the audio "the USB doesnt plug" is speak	((RejectUSB_bit = 1 or StateUSB_bit = 0) and Press button)
					
