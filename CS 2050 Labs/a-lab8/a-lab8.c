#include "lab8.h"

/*This function takes an integer data that represents age of Student. It creates a new
Student called newNode and allocates it memory. It then sets the age of Student to be data.
It also sets the next Student to be NULL. Then it returns newNode.
Input:
	int data
Output:
	Student *newNode */
Student *createNode(int data){
	Student *newNode;
	newNode=(Student*)malloc(sizeof(Student));
	if(newNode){
		newNode->age=data;
		newNode->nextPtr=NULL;
	}
	return newNode;
}

/*Intializes Student to NULL by just returning NULL
Input:
	none
Output:
	NULL*/
Student *initList(){
	return NULL;
}

/*This function takes a Student *node and an integer data (which represents the age of Student).
It then creates a temporary variable which is then intialized. After this it swaps the temp pointer
to be before the node pointer. Then it returns temp.
Input:
	Student *node
	int data
Output:
	Student *temp*/
Student *addToHead(Student *node, int data){
	Student *temp;
	temp=createNode(data);
	temp->nextPtr=node;
	return temp;
}

/*This function takes a Student *node and an integer data (which represents the age of Student).
It then creates a temporary Student *temp and intializes it with the proper data. After this
if node is NULL it just inserts it into the list because the head is also the tail. If node is not
NULL then it sifts through the list until it reaches the end. Once it reaches the end it inserts temp.
After this the head node is returned.
Input:
	Student *node
	int data
Output:
	Student *node*/
Student *addToTail(Student *node, int data){
	Student *temp;
	temp=createNode(data);

	temp->age=data;

	if(node==NULL){
		temp->nextPtr = node;
		node=temp;
	}
	else{
		Student *tail = node;
		while(tail->nextPtr!=NULL){
			tail=tail->nextPtr;
		}
		tail->nextPtr=temp;
	}

	return node;
}

/*This function takes a Student *node and prints the age of every node.
Input:
	Student *node
Output:
	none*/
void printList(Student *node){
	while(node!=NULL){
		int i=0;
		i=node->age;
		printf("%d\n", i);
		node=node->nextPtr;
	}
}

/*This function takes a Student *node and integer data and goes through the list until it finds the
first occurence of data in a nodes age. If found the location (0 based) is returned. If not then
-1 is returned
Input:
	Student *node
	int data
Output:
	int count
	or
	-1
*/
int searchAge(Student *node, int data){
	int count=0;

	while(node!=NULL){
		if((node->age)==data){
			return count;
		}
		count++;
	}
	return -1;
}

/*This function frees all allocated memory to Student *node. It sets every variable to NULL.
At the end it returns the empty list to the calling program.
Input:
	Student *node
Output:
	Student *node
*/
Student *freeList(Student *node){
	Student *temp;
	while(node!=NULL){
		temp=node;
		node=node->nextPtr;
		free(temp);
		temp=NULL;
	}
	printf("Free was successful\n");

	return node;
}
