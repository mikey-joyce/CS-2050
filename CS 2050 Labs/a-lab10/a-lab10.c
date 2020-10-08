#include "lab10.h"

Student *createStudentNode(int);

/*This function takes an integer data and creates a Student struct node
assigning the age of the student to data. It returns the new node.
Input:
  int data
Output:
  Student node*/
Student *createStudentNode(int data){
  Student *node;
  node = (Student *)malloc(sizeof(Student));
  if(node){
    node->nextPtr=NULL;
    node->age=data;
  }
  return node;
}

/*This function initializes a stack to NULL.
Input:
  none
Output:
  NULL*/
StudentList* initStack(){
  return NULL;
}

/*This function takes a StudentList node pointer and an int data.
It creates a new node and sets this to the top of the stack. If the
insertion is successful then 1 is returned. If the insertion fails -1 is
returned.
Input:
  StudentList *node
  int data
Output:
  1
  or
  -1*/
int pushStack(StudentList *node,int data){
  Student *newNode;
  newNode = createStudentNode(data);
  newNode->nextPtr=node->head;

  if(node->head==newNode->nextPtr){
    return 1;
  }
  else{
    return -1;
  }
}

/*This function takes a StudentList node pointer and deletes the head node.
It then sets the new head to be the top of the stack.
Input:
  StudentList *node
Output:
  Student *temp*/
Student* popStack(StudentList *node){
  Student *temp;
  temp=node->head->nextPtr;

  node->head->age=-1;
  node->head->nextPtr=NULL;
  free(node->head);

  return temp;
}

/*This function initializes a queue to NULL.
Input:
  none
Output:
  NULL*/
StudentList* initQueue(){
  return NULL;
}

/*This function takes a StudentList node pointer and an int data.
It makes the new head node to be the newest node with the data passed to the
function. If the insertion is successful 1 is returned if it fails -1 is
returned.
Input:
  StudentList *node
  int data
Output:
  1
  or
  -1*/
int enQueue(StudentList *node,int data){
  Student *newNode;
  newNode = createStudentNode(data);
  newNode->nextPtr=node->head;

  if(node->head==newNode->nextPtr){
    return 1;
  }
  else{
    return -1;
  }
}

/*This function takes a StudentList node pointer and traverses the queue.
Once it finds the last node it sets it to NULL and frees the allocated memory,
effectively deleting the last node of the list.
Input:
  StudentList *node
Output:
  StudentList node->head*/
Student* deQueue(StudentList *node){
  Student *temp=node->head;
  Student *temp2;

  while(temp->nextPtr!=NULL){
    temp2=temp;
    temp=temp->nextPtr;
  }
  free(temp2->nextPtr);
  temp2->nextPtr=NULL;

  return node->head;
}

/*This function takes a StudentList node pointer and traverses the list.
It prints out the age of every student.
Input:
  StudentList *node
Output:
  none*/
void printList(StudentList *node){
  Student *currentNode=node->head;
  while(currentNode!=NULL){
    int i=0;
    i=currentNode->age;
    printf("%d\n", i);
    currentNode=currentNode->nextPtr;
  }
}

/*This function frees all allocated memory.
Input:
  StudentList *node
Output:
  none*/
void freeList(StudentList *node){
  Student *temp;
  Student *currentNode=node->head;

  while(currentNode!=NULL){
    temp=currentNode;
    currentNode=currentNode->nextPtr;
    free(temp);
  }
  printf("Free was successful!");
}
