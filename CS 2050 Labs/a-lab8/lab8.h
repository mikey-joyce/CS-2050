#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct studstruct{
	int age;
	struct studstruct *nextPtr;
}Student;

Student *createNode(int);
Student *initList();
Student *addToHead(Student *, int);
Student *addToTail(Student *, int);
void printList(Student *);
int searchAge(Student *, int);
Student *freeList(Student *);
