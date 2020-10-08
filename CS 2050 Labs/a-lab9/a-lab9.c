#include "lab9.h"

/*This function takes no inputs. It allocates memory to a
dummy head node and a dummy tail node. It checks to make sure Malloc
was successful. If malloc wasn't successful NULL is returned.
If malloc is successful then it sets the age of both dummy nodes
to -1. After this it sets the next pointer of the dummy head to
the dummy tail. The next pointer of the dummy tail is set to
NULL. At the end the dummy head node is returned.
Input:
  none
Output:
  Student *dummyHead*/
Student* initListWithDummyNode(){
  Student *dummyHead=(Student*)malloc(sizeof(Student));
  Student *dummyTail=(Student*)malloc(sizeof(Student));
  if(dummyHead==NULL || dummyTail==NULL){
    printf("Malloc failed");
    return NULL;
  }
  else{
    dummyHead->age=-1;
    dummyTail->age=-1;
    dummyHead->nextPtr=dummyTail;
    dummyTail->nextPtr=NULL;
  }
  return dummyHead;
}

/*This function receives a linked list Student* and an int data value.
It then takes the data value and makes a new node to the linked
list insereted at the head of the list. After this it has a return
value of 1 if succesfully inserted and a return value of 0 if it
failed.
Input:
  Student *node
  int data
Output:
  1 (if succesful)
  or
  0 (if failed)*/
int insertToHead(Student *myList,int data){
  Student *temp;
  temp=initListWithDummyNode();

  temp->age=data;
  temp->nextPtr=myList->nextPtr;
  myList->nextPtr=temp;

  if((myList->nextPtr)==NULL){
    printf("Error inserting node.\n");
    return 0;
  }
  else{
    return 1;
  }
}

/*This function takes a Student linked list myList and an integer
data that represents an age. It creates a temporary node called
temp and initializes it. After this is checks if myList is NULL.
If myList is NULL then it inserts the tail node. Otherwise it
sifts through the linked list and inserts the data at the end
of the linked list. If the insertion failed then 0 is returned.
If the insertion was succesful then 1 is returned.
Input:
  Student *myList
  int data
Output:
  1 (if successful)
  or
  0 (if failed)*/
int insertToTail(Student *myList,int data){
  Student *temp;

  temp=initListWithDummyNode();
  temp->age=data;

  if(myList==NULL){
    myList=temp;
    return 1;
  }
  else{
    while(myList->nextPtr!=NULL){
      myList=myList->nextPtr;
    }
    myList->nextPtr=temp;
    return 1;
  }
  return 0;
}

/*In this function we have input values of Student *myList.
We traverse through the linked list and decide that since
we already initialized the age of the dummy nodes to -1 which
is not a valid age (for obvious reasons) that we will skip over
the dummy nodes and not print them out. This happens while we
traverse through the linked list. If age is not equal to -1 then it
is not the dummy node so we will print it out.
Input:
  Student *myList
Output:
  none*/
void printList(Student *myList){
  int flag=1;
  myList=myList->nextPtr;
  while(flag!=0){
    int i=0;
    i=myList->age;
    if(i==-1){
      myList=myList->nextPtr;
      continue;
    }
    printf("%d\n", i);
    myList=myList->nextPtr;
    if(myList->nextPtr == NULL){
      flag=0;
    }
  }
}

/*This function takes a Student *myList linked list as an input.
It then traverses the entire linked list and sets all of the NULL
pointers except the dummy nodes to NULL.
Input:
  Student *myList
Output:
  none*/
void emptyList(Student *myList){
  Student *temp;
  int flag=1;
  myList=myList->nextPtr;
  while (flag!=0) {
    temp=myList;
    myList=myList->nextPtr;
    temp=NULL;
    free(temp);
    if(myList==NULL){
      flag=0;
      break;
    }
  }
}

/*This function traverses the linked list and frees all memory
that was allocated.
Input:
  Student *myList
Output:
  none*/
void freeList(Student *myList){
  Student *temp;
  while (myList!=NULL) {
    temp=myList;
    myList=myList->nextPtr;
    free(temp);
  }
  printf("Free was successful\n");
}
