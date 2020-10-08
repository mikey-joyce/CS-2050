#include "lab11.h"

Student *initNode();

/*Returns NULL. I made this function so that I could initialize my Student struct
within my main during testing.
Input:
  none
Output:
  NULL;*/
Student *initNode(){
  return NULL;
}

/*This function takes no input. It then creates a variable of type queue struct. After this memory is allocated to the
pointer withing the queue struct known as list. It then initlializes everything to 0 and the head and tail pointers
to NULL. After this the queue struct variable is returned.
Input:
  none
Output:
  Queue q;
*/
Queue initQueue(){
  Queue myQueue;

  //Malloc and initialize everything within myQueue->list
  myQueue.list = malloc(sizeof(StudentList));
  myQueue.list->numOfItems=0;
  myQueue.list->numOfOdd=0;
  myQueue.list->numOfEven=0;
  myQueue.list->head=myQueue.list->tail=NULL;

  return myQueue;
}

/*This function takes in an integer data that represents the age and also takes in a Queue myQueue which represents
the queue. It then creates a new node and allocates memory to it. After this it checks to see if malloc failed. If
malloc failed then -1 is returned. After this it initlializes all the information for my node. Then it checks to see
if tail exists. If not then it adds in data there. Once the node is enqueued then 1 is returned.
Input:
  int data;
  Queue myQueue;
Output:
  -1 (if insertion fails)
  or
  1 (if insertion is successful)*/
int enQueue(int data, Queue myQueue){
  //Creates a node and allocates memory to it
  Student *node;
  node=malloc(sizeof(Student));
  //Checks if malloc failed
  if(node==NULL){
    printf("Malloc failed :(\n");
    return -1;
  }

  //Initlializes the node
  node->age=data;
  node->nextPtr=NULL;

  //Checks to see if queue is empty
  if(myQueue.list->tail==NULL && myQueue.list->head==NULL){
    //enqueues
    myQueue.list->tail=node;
    myQueue.list->tail->nextPtr=NULL;
    myQueue.list->head=node;
    myQueue.list->head->nextPtr=NULL;

    //changes the number of items and number of even/odd
    myQueue.list->numOfItems=myQueue.list->numOfItems + 1;
    //Checks if the age is even or odd
    if((node->age)%2==0){
      myQueue.list->numOfEven=myQueue.list->numOfEven + 1;
    }
    else{
      myQueue.list->numOfOdd=myQueue.list->numOfOdd + 1;
    }
  }
  else{
    //enqueues
    myQueue.list->tail->nextPtr=node;
    myQueue.list->tail=node;

    //changes the number of items and number of even/odd
    myQueue.list->numOfItems=myQueue.list->numOfItems + 1;
    //Checks if the age is even or odd
    if((node->age)%2==0){
      myQueue.list->numOfEven=myQueue.list->numOfEven + 1;
    }
    else{
      myQueue.list->numOfOdd=myQueue.list->numOfOdd + 1;
    }
  }

  return 1;
}

/*This function takes a Queue myQueue data type that represents the queue. It then creates a new node and sets it to the
head of the queue. Then it dequeues the node. After this we decrease the size of myQueue by one.
Input:
  Queue myQueue;
Output:
  Student *node;*/
Student* deQueue(Queue myQueue){
  //Declare and initialize my node
  Student *node;
  node=myQueue.list->head;

  //Dequeue the node at the head of the queue
  myQueue.list->head=node->nextPtr;
  printf("%d was dequeued\n", node->age);

  //Decrease the number of elements by one.
  myQueue.list->numOfItems=myQueue.list->numOfItems - 1;
  return node;
}

/*This function takes Queue myQueue data type that represents the queue. It then declares an
integer called size and immediately sets it to 0. After this it sets size to what was stored
in the numOfItems variable. Then size is returned.
Input:
  Queue myQueue;
Output:
  int size;*/
int getQsize(Queue myQueue){
  int size=0;

  //Obtains the size of my queue and returns it.
  size=myQueue.list->numOfItems;
  return size;
}

/*This function takes Queue myQueue data type that represents the queue. It then declares an
integer called even and immediately sets it to 0. After this it is set to be the number
that is stored in numOfEven. Then even is returned.
Input:
  Queue myQueue;
Output:
  int even;*/
int getNumOfEven(Queue myQueue){
  int even=0;

  even=myQueue.list->numOfEven;
  return even;
}

/*This function takes Queue myQueue data type as input. It then sets node to be the head
of the list. Then it traverses the queue and prints out the age value for every member of
the queue.
Input:
  Queue myQueue;
Output:
  none*/
void printQueue(Queue myQueue){
  Student *node=myQueue.list->head;
  while(node!=NULL){
    printf("%d\n", node->age);
    node=node->nextPtr;
  }
}

/*This function takes Queue myQueue data type as input. It then creates a variable
node and sets it the the head of the queue. After this it traverses the queue and frees each
malloced node. After it is done traversing the queue it frees the list pointer within
myQueue. Then a print statement prints out free was successful.
Input:
  Queue myQueue;
Output:
  none*/
void emptyQueue(Queue myQueue){
  Student *node=myQueue.list->head;

  while(node!=NULL){
    Student *newHead;
    newHead=node->nextPtr;
    free(node);
    node=newHead;
  }
  free(myQueue.list);
  printf("Free was successful\n");
}
