#include "a-prelab8.h"

List * initIntegerList(){
	List *dummy;
	dummy = (List*)malloc(sizeof(List));
	dummy->next=NULL;
	dummy->data=5;

	return dummy;
}

int insertAtHead(int myData, List *myList){
	List *temp;
	temp=initIntegerList();

	temp->data=myData;
	temp->next=myList->next;
	myList->next=temp;

	if((myList->next)==NULL){
		printf("Error inserting node.\n");
		return 1;
	}
	else{
		return 0;
	}
}

int insertAtTail(int myData, List *myList){
	List *temp;
	//List *temp2;

	temp=initIntegerList();
	temp->data=myData;
	if(myList==NULL){
		myList=temp;
	}
	else{
		//temp2=myList;
		while(myList->next!=NULL){
			myList = myList->next;
		}
		myList->next=temp;
	}
	return 0;
}

void printList(List *myList){
	printf("Here is the list: \n");
	myList=myList->next;
	while(myList!=NULL){
		int i=0;
		i=myList->data;
		printf("\t%d\n", i);
		myList = myList->next;
	}
	printf("List done printing\n");
}

void freeList(List *myList){
	List *temp;
	while(myList != NULL){
		temp=myList;
		myList=myList->next;
		free(temp);
	}
	printf("Free was successful\n");
}
