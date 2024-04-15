#include <bits/stdc++.h>
#include <vector>
using namespace std;

/********************************************************************************
 Vector is dynamic array in c++
 cyntax:		vector<<data_type>> <ten vector>		or		vector<<data_type>> <ten vector>(<so' phan` tu~ muon' khoi~ tao.>, <gia' tri. tung` phan` tu~ khoi~ tao.>)
 example:		vector<int> v1;											or		vector<int> v2(15, 4);	//tao. ra 15 phan` tu~ co' gia' tri. ban dau` la` 4
	
 commands:
	- <vector>.size()														size of vector
	- <vector>.push_back(<value>)								insert last of array
	- <vector>.insert(*position, value)					insert value at anywhere
	- *<vector>.begin()													truy xuat' phan` tu~ dau` tien
	- <vector>.back()														truy xuat' phan` tu~ cuoi'
	- *<vector>.end()														truy xuat' phan` tu~ sau phan` tu~ cuoi' cung`
	- <vector>.erase(*position)									xoa' phan` tu~ thu' position
		<vector>.erase(*s_position, *e_position)	xoa' tu` phan` tu~ thu' s_position -> e_position
	- <vector>.clear()													xoa' toan` bo. vector		---		xoa' la` khien' cho size cua~ vector = 0, data tai. vung` nho' do' khong thay doi
*/

int main(void){
	/* init vector */
	vector<int> v1;
	
	/* push_back(x) */
	v1.push_back(10);
	v1.push_back(20);
	v1.insert(v1.begin()+0, 50);
	v1.push_back(30);
	v1.erase(v1.begin());
	v1.clear();
	
	/* size() */
	cout <<"size of v1: " <<v1.size() <<"\n";	//result: 3
	
	/* Truy xuat' phan` tu~ thong thuong` */
	cout <<"value v[0]: " <<v1[0] <<"\n";	//result: 10
	cout <<"value last (v1[2]): " <<v1[(v1.size() - 1)] <<"\n"; //result: 30
	
	/* back() */
	cout <<"value first (v1[0]): " <<*v1.begin() <<"\n"; //result: 10
	cout <<"value last (v1[2]): " <<v1.back() <<"\n"; //result: 30
	cout <<"value end (v1[3]): " <<*v1.end() <<"\n"; //result: 0
	int* a = new int;
	*a = 9;
	cout <<"value end (v1[3]): " <<*v1.end() <<"\n"; //result: 0 -->> why isn't 9 ????
	delete(a);
	
	/* in Developer C/C++ IDE, cap' phat' dong. 'new' se~ cho 1 vung` nho' random chu' khong lien` ke` nhau nhu vector */
	int* p1 = new int;
	*p1 = 1;
	int* p2 = new int;
	*p2 = 2;
	int* p3 = new int;
	*p3 = 3;
	cout <<"address p1: " <<p1 <<"   -----   " <<"address p2: " <<p2 <<"   -----   " <<"address p3: " <<p3<<"\n";
	delete(p1, p2, p3);
	cout <<"address p1: " <<&v1[0] <<"   -----   " <<"address p2: " <<&v1[1] <<"   -----   " <<"address p3: " <<&v1[2] <<"\n";
	
	vector<int> v2(15, 4);
	char i=0;
	cout <<"\narray v2: ";
	while (v2[i] != '\0'){
		cout <<v2[i] <<"\t";	//chi~ 15 gia' tri. dau` tien = 4, do o~ vung` nho' heap co' 1 so' noi co gia' tri. random nen while NULL co' the~ in ra nhieu` hon 15 phtu~
		i++;
	}
	cout <<"\n";
	
	return 0;
}
