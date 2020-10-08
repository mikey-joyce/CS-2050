#include "lab12.h"

/*This function takes no input and returns an empty queue that is
properly intialized.
Input:
  none
Output:
  PQueue myQueue;*/
PQueue initPQueue(){
  //Declare my queue
  PQueue myQueue;

  //allocate memory to the list of my queue
  myQueue.list=malloc(sizeof(StudentList));

  //initialize the size of my queue to 0
  myQueue.list->numOfItems=0;

  //initialize the head and tail of my queue to be NULL
  myQueue.list->head=myQueue.list->tail=NULL;

  return myQueue;
}

/*This function takes a float priority and an int data as inputs. It then
allocates memory and initlializes a new node of the Student struct. If memory
allocation failed then NULL is returned. If the node was properly initialized
then the pointer to the node is returned.
Input:
  float priority;
  int data;
Output:
  Student *node;*/
Student *createNode(float priority, int data){
  //Allocate memory for the new node
  Student *node=malloc(sizeof(Student));

  //Check to see if malloc worked
  if(node==NULL){
    //Malloc failed so NULL is returned
    return NULL;
  }

  //Initialize the Student node with the given data
  node->age=data;
  node->priority=priority;
  node->nextPtr=NULL;
  node->previousPtr=NULL;

  //Return the new node to the calling program
  return node;
}

/*This function takes a float priority, an int data and an instance of
the PQueue struct called myQueue. It then creates a new node with the given data.
After this it checkes where it should insert the Node into the list based on its
priority. The greater the priority the closer to the head the node will be placed.
If -1 is ever returned then the insertion failed. If 1 is returned then the
insertion was successful.
Input:
  float priority;
  int data;
  PQueue myQueue;
Output:
  -1 (if failed)
  or
  1 (if successful)*/
int insertPQ(float priority, int data, PQueue myQueue){
      //Alias to the StudentList *
      StudentList *list = myQueue.list;

      //Check list info
      if(list == NULL){
          return -1;
      }

      //Create a new Node
      Student *node = createNode(priority, data);

      //If new node is valid
      if(node){
          //Increment the number of items
          list->numOfItems++;

          //If the queue is empty
          if (list->head == NULL && list->tail == NULL) {
              //Set the head and tail to be the new node
              list->head = node;
              list->tail = node;

              //success
              return 1;

          }
      //If list is not empty, search through the entire queue until the lower priority is found and insert before

      if (list->head->priority < node->priority){ //If the head priority is less than the node priority
              //node becomes the new head
              //insert before old head

              //Point to old head
              node->nextPtr = list->head;

              //point old head previous to the new node
              list->head->previousPtr = node;

              //new node becomes head
              list->head = node;
          }
          else {
              //Iterate through rest
              Student *temp = list->head;

              //Find the pointer with the next priority smaller than the new priority
              while (temp->nextPtr != NULL && temp->nextPtr->priority > node->priority) {
                  temp = temp->nextPtr;
              }
              //Insert in between temp (larger priority) and temp->next (smaller priority)

              //Check if the next pointer is not null
              if (temp->nextPtr != NULL) {
                  //Tell next pointer to point backwards to weather node
                  temp->nextPtr->previousPtr = node;
              }else {
                  //If it is null, mark the node as the tail
                  list->tail = node;
              }
              //Insert node between p and p->next

              //Next after weather node is p->next
              node->nextPtr = temp->nextPtr;

              //weather node previous points back to p
              node->previousPtr = temp;

              //p->next now points to new weather node
              temp->nextPtr = node;
          }
          //Success return 1
          return 1;
      }
      else {
          //Fail return -1
          return -1;
      }
}

/*This function takes an instance of the PQueue struct called myQueue as input.
It then sets the new tail to be the previous of the current tail. It severs all
connections between the old tail and new tail. If the deletion failed then
NULL is returned otherwise the pointer to the delted node is returned.
Input:
  PQueue myQueue;
Output:
  //old tail of the list
  Student *returnVal*/
Student *deleteMin(PQueue myQueue){
    //Alias to the Student struct
    Student *myNode=myQueue.list->tail;
    Student *returnVal=myQueue.list->tail;

    //Sets the new tail to be the previous of the old tail.
    myQueue.list->tail=myNode->previousPtr;

    //Severs all connections between the old tail and new tail
    myNode->previousPtr->nextPtr=NULL;
    myNode->previousPtr=NULL;
    myNode->nextPtr=NULL;

    return returnVal;
  }

/*This function takes an instance of the PQueue struct called myQueue as
input. Then it sets the new head to be the next of the current head. Then
it severs all connections between the two nodes. If NULL is returned then the
deletion failed. If the deletion succeeded then the pointer to the removed
node is returned.
Input:
  PQueue myQueue
Output:
  //old head of the list
  Student *returnVal*/
Student *deleteMax(PQueue myQueue){
    //Alias to the Student struct
    Student *myNode=myQueue.list->head;
    Student *returnVal=myQueue.list->head;

    //Sets the new head to be the next of the old head.
    myQueue.list->head=myNode->nextPtr;

    //Severs all connections between the two nodes
    myNode->previousPtr=NULL;
    myNode->nextPtr->previousPtr=NULL;
    myNode->nextPtr=NULL;

    return returnVal;
  }

/*This function takes an instance of the PQueue struct called myQueue as input.
Then it outputs the tail of the list which is the minimum priority member.
Input:
  PQueue myQueue;
Output:
  //tail of the list
  myQueue.list->tail;*/
Student *returnMin(PQueue myQueue){
  //returns tail of the list
  return myQueue.list->tail;
}

/*This function takes an instance of the PQueue struct called myQueue as input.
Then it outputs the head of the list which is the maximum priority member.
Input:
  PQueue myQueue;
Output:
  //head of the List
  myQueue.list->head*/
Student *returnMax(PQueue myQueue){
  //returns head of the list
  return myQueue.list->head;
}

/*This function takes PQueue myQueue as input. Then it frees all allocated
memories in the program. Nothing is returned to the calling program.
Input:
  PQueue myQueue;
Output:
  none*/
void freePQueue(PQueue myQueue){
  //Alias to the Student struct
  Student *node=myQueue.list->head;

  //Traverses the list to free every member
  while(node!=NULL){
    //Alias to the Student struct
    Student *newHead;

    //Sets this before freeing because after free we will no longer have access to node
    newHead=node->nextPtr;

    //frees current node
    free(node);

    //resets our node for the next iteration
    node=newHead;
  }
  //After all node memory is freed we must free the list memory
  free(myQueue.list);
}

/*This function takes an instance of PQueue myQueue as input. It then traverses
the queue and prints out the priority and age of every member. Nothing is returned
to the calling program.
Input:
  PQueue myQueue;
Output:
  none;*/
void printPQueue(PQueue myQueue){
  //Alias to the Student struct
  Student *node=myQueue.list->head;

  //Traverses the queue
  while(node!=NULL){
    //Prints the priority and age in the given format: priority(age)
    printf("%lf(%d)\n", node->priority, node->age);
    //resets our node for the next iteration
    node=node->nextPtr;
  }
}
