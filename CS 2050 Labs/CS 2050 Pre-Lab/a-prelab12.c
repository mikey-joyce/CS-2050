#include<stdio.h>
#include<stdlib.h>

typedef struct nodestruct{
  float data;
  float priority;
  struct nodestruct *next;
  struct nodestruct *back;
}Node;

typedef struct linkedlist{
  Node *head, *tail;
  int size;
}List;

typedef struct pqueuestruct{
  List *list;
}PQueue;

PQueue initPQ(); //Return empty priority queue
int insertPQ(float, float, PQueue); //priorities are floats //1st value used to be of type void*
void *deleteMin(PQueue);
void *deleteMax(PQueue);
void *returnMin(PQueue); //returns but does not delete
void *returnMax(PQueue); //returns but does not delete
int getSizePQ(PQueue); //returns # of items in queue
void freePQ(PQueue); //Free all malloced space
void printQueue(PQueue);
Node *createNode(float, float);//Creates an instance of the Node struct

int main(void){
  float i=0.0;
  int flag=0;
  PQueue myQueue=initPQ();
  Node *min=NULL;
  Node *max=NULL;

  flag=insertPQ(i, 1.0, myQueue);
  flag=insertPQ(i, 2.0, myQueue);
  flag=insertPQ(i, 4.0, myQueue);
  flag=insertPQ(i, 3.0, myQueue);
  min=returnMin(myQueue);
  max=returnMax(myQueue);
  printf("Size of queue: %d\n", getSizePQ(myQueue));
  printf("Max: \n\t%lf\n", max->priority);
  printf("Min: \n\t%lf\n", min->priority);
  printf("Test insertion ");
  printQueue(myQueue);

  deleteMax(myQueue);
  deleteMin(myQueue);

  printf("Test deletion ");
  printQueue(myQueue);
  freePQ(myQueue);
}

/*Initlializes the priority queue to be empty.*/
PQueue initPQ(){
  PQueue myQueue;

  myQueue.list=malloc(sizeof(List));
  myQueue.list->size=0;
  myQueue.list->head=myQueue.list->tail=NULL;

  return myQueue;
}

Node *createNode(float priority, float temperature){
  Node *node=malloc(sizeof(Node));
  if(node==NULL){
    printf("Malloc failed :(\n");
    return NULL;
  }

  node->data=temperature;
  node->priority=priority;
  node->next=NULL;
  node->back=NULL;

  return node;
}

int insertPQ(float data, float priority, PQueue myQueue) {

    //Alias to the List *
    List *list = myQueue.list;

    //Null check List info
    if (list == NULL) {
        return -1;
    }

    //Create a new Node
    Node * node = createNode(priority, data);

    //If valid
    if (node) {
        //Increment the number of items
        list->size++;

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
            node->next = list->head;

            //point old head previous to the new node
            list->head->back = node;

            //new node becomes head
            list->head = node;
        }
        else {
            //Iterate through rest
            Node * temp = list->head;

            //Find the pointer with the next priority smaller than the new priority
            while (temp->next != NULL && temp->next->priority > node->priority) {
                temp = temp->next;
            }

            //Insert in between temp (larger priority) and temp->next (smaller priority)

            //Check if the next pointer is not null
            if (temp->next != NULL) {
                //Tell next pointer to point backwards to weather node
                temp->next->back = node;
            }else {
                //If it is null, mark the node as the tail
                list->tail = node;
            }

            //Insert node between p and p->next

            //Next after weather node is p->next
            node->next = temp->next;

            //weather node previous points back to p
            node->back = temp;

            //p->next now points to new weather node
            temp->next = node;


        }

        //Success return 1
        return 1;

    }else {

        //Fail return -1
        return -1;
    }

}

/*Deletes the tail of the list by breaking of the connections in the linked
list between the other nodes so it can no longer be accessed by the list. Then
the head of the list is returned.*/
void *deleteMin(PQueue myQueue){
  Node *myNode=myQueue.list->tail;
  myQueue.list->tail=myNode->back;
  myNode->back->next=NULL;
  myNode->back=NULL;
  myNode->next=NULL;

  return myQueue.list->head;
}

/*Severs connections of the head of the queue and creates a new head of the
queue. Then the head is returned.*/
void *deleteMax(PQueue myQueue){
  Node *myNode=myQueue.list->head;
  myQueue.list->head=myNode->next;
  myNode->back=NULL;
  myNode->next->back=NULL;
  myNode->next=NULL;

  return myQueue.list->head;
}

/*Returns the tail of the list.*/
void *returnMin(PQueue myQueue){
  return myQueue.list->tail;
}

/*Returns the head of the list.*/
void *returnMax(PQueue myQueue){
  return myQueue.list->head;
}

/*Returns the size of the queue.*/
int getSizePQ(PQueue myQueue){
  return myQueue.list->size;
}

void freePQ(PQueue myQueue){
  Node *node=myQueue.list->head;

  while(node!=NULL){
    Node *newHead;
    newHead=node->next;
    free(node);
    node=newHead;
  }
  free(myQueue.list);
  printf("Free was successful!\n");
}

void printQueue(PQueue myQueue){
  Node *node=myQueue.list->head;

  printf("PQueue:\n");
  while(node!=NULL){
    printf("\t%lf\n", node->priority);
    node=node->next;
  }
}
