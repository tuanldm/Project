#include <bits/stdc++.h>

using namespace std;

/*************************************************************************
Linked List:
	- Every Node has Data and Address of the next Node
	- Functions:
		+ Add a Node
			. Add first
			. Add Last
			. Add anywhere
		+ Delete a Node anywhere
		+ Print Linked List
*/

//
struct Node{ // 1 node luon gom` 2 phan` la` data cua~ node va con tro~ de~ tro~ vao` dia. chi~ cua~ node tiep' theo
	int data;
	Node* nextAddress;
};

//xin cap' phat' 1 vung` nho' co' kich' thuoc' bang` 1 struct Node voi' data dau` vao` input
struct Node* makeNode(int input){
	struct Node* temp = new Node(); // Node() la` struct Node o tren   --- tmp la` mot. con tro~ kieu Node
	(temp -> data) = input;
	(temp -> nextAddress) = NULL; // khi tao. ra 1 note thi` phan` dia. chi sau cung` luon tro~ vao` NULL
	
	cout <<(temp -> data) <<"\t" <<(temp -> nextAddress) <<"\n";
	return temp;
};

//Kiem~ tra rong~
bool checkEmpty(struct Node* input){
	return (input == NULL);
}

//kiem~ tra xem LinkList co bao nhieu Node
int checkSize(struct Node* input){
	int count = 0;
	while (input != NULL){ //vi` Node cuoi' cung` co' con tro~ tro~ ve NULL
		input = (input -> nextAddress); //gan gia tri. con tro~ hien. tai. = gia' tri. con tro~ cua Node tiep theo
		count++;
	}
	return count;
}

//them 1 Node vao` DAU` LinkList
void insertFirst(struct Node* &input, int x){ //dung` con tro~ de tro~ den' con tro~ khac' -- x la` value Node muon' tao.
	struct Node* temp = makeNode(x);
	if (input == NULL){  //truong` hop. LinkList chua co Node nao`
		input = temp;
	}
	else{ //truong` hop. LinkList da~ co san~ Node
		(temp -> nextAddress) = input; //khi moi' khoi~ tao. con tro~ "nextAddress" cua~ temp se~ tro~ vao` NULL. 
																	//Do do' ta se~ tro~ no vao` dia. chi~ cua Node input 
		input = temp;
	}
}

//them 1 Node vao` CUOI' LinkList
void insertLast(struct Node* &input, int x){ //dung` con tro~ de tro~ den' con tro~ khac' -- x la` value Node muon' tao.
	struct Node* temp = makeNode(x);
	if (input == NULL){  //truong` hop. LinkList chua co Node nao`
		input = temp;
	}
	else{ //truong` hop. LinkList da~ co san~ Node
		struct Node* p = input;	//ta khong dung` truc. tiep' input de~ duyet. vi` se~ mat' head Node
		while ((p -> nextAddress) != NULL){	//duyet. LinkList de~ tim` ra  Node cuoi' cung`
			p = (p -> nextAddress);							//Node cuoi' cung` la` Node co' con tro~ nextAddress = NULL
		}
		(p -> nextAddress) = temp;
	}
}

//them 1 Node vao` vi. tri' BAT' KI` cua LinkList
void insertPosition(struct Node* &input, int pos, int x){ //dung` con tro~ de tro~ den' con tro~ khac' -- pos la` vi. tri' chen` Node
	int n = checkSize(input);	//kiem~ tra xem Node co' bao nhieu phan` tu~ (0 < n <= n+1)
	if ((pos <= 0) || (pos > n+1)){
		cout <<"position is not allowed\r\n";
	}
	else{
		if (pos == 1){
			insertFirst(input, x);
		}
		else if (pos == n+1){
			insertLast(input, x);
		}
		else{
			struct Node* temp = makeNode(x);
			struct Node* p = input;	//ta khong dung` truc. tiep' input de~ duyet. vi` se~ mat' head Node
			for (int i = 1; i < (pos-1); i++){	//duyet den Node can` chen`
				p = p -> nextAddress;
			}
			(temp -> nextAddress) = (p -> nextAddress);	//con tro~ "nextAddress" cua~ p dang tro~ vao` Node tiep theo
			(p -> nextAddress) = temp;	//con tro~ "nextAddress" cua~ p tro~ vao` Node vua` them
		}
	}
}

//xoa' Node dau` tien
void deleteFirst(struct Node* &input){
	if (input == NULL){	//neu' chua co Node nao thi return luon
		return;
	}
	struct Node* temp = input;
	temp = (temp -> nextAddress);
	(input -> nextAddress) = NULL;
	input = temp;
}

//xoa' Node cuoi' cung`
void deleteLast(struct Node* &input){
	if (input == NULL){ //neu' chua co Node nao thi return luon
		return;
	}
	else{
		struct Node* temp_1 = NULL;		//de xoa' Node cuoi' cung` ta can` truy xuat' den' Node cuoi'
		struct Node* temp_2 = input;	//va` xoa' con tro~ "nextAddress" cua~ Node ngay truoc' do' ve NULL
		while ((temp_2 -> nextAddress) != NULL){ //neu' con tro~ "nextAddress" = NULL thi` do' chinh' la` Node cuoi'
			temp_1 = temp_2;									//Node thu' n-1
			temp_2 = (temp_2 -> nextAddress);	//Node thu' n
		}
		if ((temp_1 -> nextAddress) == NULL){ //chi~ co' 1 Node duy nhat' nen temp_1 chua duoc. gan' = temp_2
			input = NULL;
		}
		else {
			(temp_1 -> nextAddress) = NULL;	//xoa' Node cuoi' cung`
		}	
	}
}

//xoa' Node o~ vi. tri' bat' ki` 
void deletePosition(struct Node* &input, int pos){
	int n = checkSize(input);
	if ((pos <= 0) || (pos >= n+1)){
		cout <<"position is not allowed\r\n";
	}
	else{
		if (pos == 1){
			deleteFirst(input);
		}
		else if (pos == n){
			deleteLast(input);
		}
		else{	//xoa' Node tai. vi. tri' pos la` gan' "nextAddress" tai. pos-1 = voi "nextAddress" tai. pos roi` gan' "nextAddress" tai. pos = NULL
			struct Node* temp_1 = NULL;
			struct Node* temp_2 = input;
			for (int i = 1; i < pos; i++){
				temp_1 = temp_2;
				temp_2 = (temp_2 -> nextAddress);
			}
			(temp_1 -> nextAddress) = (temp_2 -> nextAddress); 
			(temp_2 -> nextAddress) = NULL;
		}
	}
}

void printListNode(struct Node* input){
	cout <<"-------------LinkList-----------\r\n";
	if (input == NULL){
		cout <<"Node empty\r\n";
		return;
	}
	else{
		while ((input -> nextAddress) != NULL){
			cout <<(input -> data) <<"\t";
			input = (input -> nextAddress);
		}
		cout <<(input -> data) <<"\t";
		cout <<"\n-------------end-----------\r\n";
	}
}

int main(void){
	int select = 0;
	int value;
	int position;
	
	struct Node* head = NULL; //khoi~ tao. head 
	
	cout <<"size of Node: " <<sizeof(Node) <<"\r\n\n";
	
	while(1){
		cout <<"----------MENU-------\r\n";
		cout <<"select 1: insert first Node\r\n";
		cout <<"select 2: insert last Node\r\n";
		cout <<"select 3: insert Node\r\n";
		cout <<"select 4: delete Node\r\n";
		cout <<"select 5: print LinkList\r\n";
		cout <<"your choose is:\t"; cin >>select; 
		if (select == 1){
			cout <<"input value: "; cin >>value;
			insertFirst(head, value);
			cout <<"insert done\r\n\n";
		}
		else if (select == 2){
			cout <<"input value: "; cin >>value;
			insertLast(head, value);
			cout <<"insert done\r\n\n";
		}
		else if (select == 3){
			cout <<"input position: "; cin >>position;
			cout <<"input value: "; cin >>value;
			insertPosition(head, position, value);
			cout <<"insert done\r\n\n";
		}
		else if (select == 4){
			cout <<"input position: "; cin >>position;
			deletePosition(head, position);
			cout <<"delete done\r\n\n";
		}
		else if (select == 5){
			printListNode(head);
			cout <<"print done\r\n\n";
		}
	}
	return 0;
}
