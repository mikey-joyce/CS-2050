#include<stdio.h>
#include<stdlib.h>

typedef struct listStruct{
	int data;
	struct listStruct *next;
}List;

List * initIntegerList();
int insertAtHead(int , List*);
int insertAtTail(int, List*);
void printList(List*);
void freeList(List*);
