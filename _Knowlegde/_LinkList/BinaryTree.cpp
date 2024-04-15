#include <bits/stdc++.h>
#include <vector>

using namespace std;

/**********************************************************************************
Binary Tree
	- Every NodeTree has Data and 2 Addresses are left and right which contain 2 NodeTree others
	- Functions of Binary Tree:
		+ Add NodeTree  
		+ Delete NodeTree
		+ Print Node List
		+ Check/Find a Data into Binary Tree
*/

vector<int> g_vector_as32;

/* implements of a Node Tree */
struct Tree{
	int dataTree;
	struct Tree* leftAddress;
	struct Tree* rightAddress;
};

/* Create a Node Tree */
struct Tree* makeNodeTree(int p_inputData_s32){
	struct Tree* f_temp_str = new Tree();
	(f_temp_str -> leftAddress) = NULL;
	(f_temp_str -> dataTree) = p_inputData_s32;
	(f_temp_str -> leftAddress) = NULL;
	
	//cout <<(f_temp_str -> leftAddress) <<"\t" <<(f_temp_str -> dataTree) <<"\t" <<(f_temp_str -> rightAddress) <<"\n";
	return f_temp_str;
};

/**************************************************************
Insert a Node Tree ----- left less || right large
	- Instance 1:	First Node Tree
	- Instance 2:	Head Node is available
		+ the Data of NodeTree is less -> this NodeTree is leftAddress of parent node   
		+ the Data of NodeTree is large -> this NodeTree is rightAddress of parent node   
*/
void InsertNodeTree(struct Tree* &p_headNodeTree_str, int p_valueTree_s32){
	struct Tree* f_temp_str = makeNodeTree(p_valueTree_s32);
	
	if (p_headNodeTree_str == NULL){
		p_headNodeTree_str = f_temp_str;
	}
	else {
		struct Tree* f_temp2_str = p_headNodeTree_str;		//use a temp variable to pass to intend to don't loss head
		struct Tree* f_temp3_str = new Tree();						//temp3 = the previous temp2 
		while( (f_temp2_str) != NULL ){
			f_temp3_str = f_temp2_str;											//temp3 = the previous temp2
			
			/* find position of NodeTree which we need to add */
			if ((f_temp_str -> dataTree) < (f_temp2_str -> dataTree)){
				f_temp2_str = (f_temp2_str -> leftAddress);
			}
			else if ((f_temp_str -> dataTree) > (f_temp2_str -> dataTree)){
				f_temp2_str = (f_temp2_str -> rightAddress);
			}
			else {
				cout <<"the value is existance! \n";
				goto OUT_CONDITION;
			}
		}

		/* add NodeTree into position of f_temp2_str */
		if ((f_temp_str -> dataTree) < (f_temp3_str -> dataTree)){
			(f_temp3_str -> leftAddress) = f_temp_str;
		}
		else if ((f_temp_str -> dataTree) > (f_temp3_str -> dataTree)){
			(f_temp3_str -> rightAddress) = f_temp_str;
		}
		
		OUT_CONDITION:;	//if the value is existance -> break 
	}
}

/* Traverse Binary Tree */
void TraverseTree(struct Tree* &p_headNodeTree_str){
	if (p_headNodeTree_str == NULL){
		cout <<"Don't find value of Tree\n";
	}
	else {
		/*******************************************************************************************
			
		*/
		/* Initial data */
		struct Tree* f_temp_str = p_headNodeTree_str;
		struct Tree* f_tempLeft_str = (f_temp_str -> leftAddress);
		struct Tree* f_tempRight_str = (f_temp_str -> rightAddress);
		int f_sttVector_s32 = 0;
		g_vector_as32.clear();
		
		/* vector[0] */
		g_vector_as32.push_back(f_temp_str -> dataTree);
		
		/* traverse vector[] and add new value if detect */
		while ( f_sttVector_s32 < g_vector_as32.size() ){
			/* find position of vector[f_sttVector_s32] */
			f_temp_str = p_headNodeTree_str;
			while (f_temp_str != NULL){
				if (g_vector_as32[f_sttVector_s32] < (f_temp_str -> dataTree)){
					f_temp_str = (f_temp_str -> leftAddress);
				}
				else if (g_vector_as32[f_sttVector_s32] > (f_temp_str -> dataTree)){
					f_temp_str = (f_temp_str -> rightAddress);
				}
				else{
					break;
				}
			}
			
			/* assign f_tempLeft_str and f_tempRight_str by Data of vector[f_sttVector_s32]'s left/right Address */
			f_tempLeft_str = (f_temp_str -> leftAddress);
			f_tempRight_str = (f_temp_str -> rightAddress);
			if (f_tempLeft_str != NULL){
				g_vector_as32.push_back(f_tempLeft_str -> dataTree);
			}
			if (f_tempRight_str != NULL){
				g_vector_as32.push_back(f_tempRight_str -> dataTree);
			}
			
			/* gain traversation value of vector */
			f_sttVector_s32++;
		}
		
		
		/* Print */
		cout <<"Data List of Tree:  \t";
		for (int i=0; i<f_sttVector_s32; i++){	
			cout <<g_vector_as32[i] <<"\t";
		}
		cout <<"\n";
	}
}

/* Check Data existance or not */
bool FindData(struct Tree* &p_headNodeTree_str, int p_dataFind){
	struct Tree* f_temp_str = p_headNodeTree_str;
	
	while (f_temp_str != NULL){
		if (p_dataFind == (f_temp_str -> dataTree)){
			cout <<"Value is existancing in Tree \n";
			return 1;
		}
		else if (p_dataFind < (f_temp_str -> dataTree)){
			f_temp_str = (f_temp_str -> leftAddress);
		}
		else if (p_dataFind > (f_temp_str -> dataTree)){
			f_temp_str = (f_temp_str -> rightAddress);
		}
	}
	cout <<"Value is not existance in Tree \n";
	return 0;
}

/*************************************************
Delete a NodeTree
	* First, we must check unless the value existance or not
	- Instance 1: That NodeTree doesn't contain any NodeTree child
			+ Delele it
	- Instance 2: That NodeTree contain a NodeTree child
			+ Use that NodeTree child to instead of NodeTree deleted
	- Instance 3: That NodeTree contain 2 NodeTree children
			+ Traverse implements from the Node Tree which we want to delete
			+ Insert implements traversed before
*/
void DeleteNodeTree(struct Tree* &p_headNodeTree_str, int p_dataDelete_s32){
	bool f_check_bool = 0;
	/* Check value unless it existance or not */
	f_check_bool = FindData(p_headNodeTree_str, p_dataDelete_s32);
	
	if (f_check_bool == 0){
		cout <<"Value doesn't existance!!!\n";
	}
	else {
		struct Tree* f_temp_str = p_headNodeTree_str;
		struct Tree* f_temp2_str = new Tree();	//temp2 = the previous temp
		
		/* find to position of the value which we want to delete */
		while (f_temp_str != NULL){
			if (p_dataDelete_s32 == (f_temp_str -> dataTree)){
				cout <<"Value is existancing in Tree \n";
				break;
			}
			else if (p_dataDelete_s32 < (f_temp_str -> dataTree)){
				f_temp2_str = f_temp_str;									//temp2 = the previous temp
				f_temp_str = (f_temp_str -> leftAddress);
			}
			else if (p_dataDelete_s32 > (f_temp_str -> dataTree)){
				f_temp2_str = f_temp_str;									//temp2 = the previous temp
				f_temp_str = (f_temp_str -> rightAddress);
			}
		}
		
		/* Instance 1: That NodeTree doesn't contain any NodeTree child */
		if ( ((f_temp_str -> leftAddress) == NULL) && ((f_temp_str -> rightAddress) == NULL) ){
			if (p_dataDelete_s32 < (f_temp2_str -> dataTree)){
				(f_temp2_str -> leftAddress) = NULL;
			}
			else if (p_dataDelete_s32 > (f_temp2_str -> dataTree)){
				(f_temp2_str -> rightAddress) = NULL;
			}
			f_temp_str -> dataTree = '\0';
		}
		/* Instance 2: That NodeTree contain a NodeTree child */
		else if ( ((f_temp_str -> leftAddress) == NULL) || ((f_temp_str -> rightAddress) == NULL) ){
			struct Tree* f_temp3_str = f_temp_str;	//save as f_temp_str to clear Value
			/* */
			if ((f_temp3_str -> leftAddress) == NULL){
				f_temp3_str = (f_temp3_str -> rightAddress);
			}
			else if ((f_temp3_str -> rightAddress) == NULL){
				f_temp3_str = (f_temp3_str -> leftAddress);
			}
			/* */
			if ((f_temp2_str -> dataTree) < (f_temp3_str -> dataTree)){
				(f_temp2_str -> rightAddress) = f_temp3_str;
			}
			else if ((f_temp2_str -> dataTree) > (f_temp3_str -> dataTree)){
				(f_temp2_str -> leftAddress) = f_temp3_str;
			}
			
			/* Clear Value */
			(f_temp_str -> dataTree) = '\0';
			(f_temp_str -> leftAddress) = NULL;
			(f_temp_str -> rightAddress) = NULL;
		}
		/* Instance 3: That NodeTree contain 2 NodeTree children */
		else {			
			/* traverse from the delete value */
			TraverseTree(f_temp_str);
			
			/* delete node Tree */
			if (p_dataDelete_s32 < (f_temp2_str -> dataTree)){
				(f_temp2_str -> leftAddress) = NULL;
			}
			else if (p_dataDelete_s32 > (f_temp2_str -> dataTree)){
				(f_temp2_str -> rightAddress) = NULL;
			}
			f_temp_str -> dataTree = '\0';
			(f_temp_str -> leftAddress) = NULL;
			(f_temp_str -> rightAddress) = NULL;
			
			/* Insert from temp2 to save time more head */
			for (int i=1; i<g_vector_as32.size(); i++){	//i=0 <=> value which want to delete, so i=1
				InsertNodeTree(f_temp2_str, g_vector_as32[i]);	
			}
		}
	}
	
}

int main(void){
	int select;
	int value;
	int position;
	
	struct Tree* head = NULL; //khoi~ tao. head 
	
	cout <<"size of Node: " <<sizeof(Tree) <<"\r\n\n";
	
	while(1){
		cout <<"----------MENU-------\r\n";
		cout <<"select 1: insert NodeTree\r\n";
		cout <<"select 2: delete Node\r\n";
		cout <<"select 3: check Value\r\n";
		cout <<"select 4: print TreeList\r\n";
		cout <<"your choose is:\t"; cin >>select; 
		if (select == 1){
			cout <<"input value: "; 
			cin >>value;
			InsertNodeTree(head, value);
			cout <<"insert done\r\n\n";
		}
		else if (select == 2){
			cout <<"input value which want to delete: "; cin >>value;
			DeleteNodeTree(head, value);
			cout <<"delete done\r\n\n";
		}
		else if (select == 3){
			cout <<"input Value which want to check: "; cin >>value;
			FindData(head, value);
			cout <<"\n";
		}
		else if (select == 4){
			TraverseTree(head);
			cout <<"print done\r\n\n";
		}
		/* Reset Data */
		select = 0;	
		value = 0;
	}
	return 0;
}
