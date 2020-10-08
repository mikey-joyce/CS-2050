#include<stdio.h>
#include<stdlib.h>
typedef struct nodestruct
{
    int data;
    struct nodestruct *next;
}node;

typedef struct qinfo
{
    int size;
    node *head;
    node *tail;

}qinfo;

typedef struct qstruct
{
    qinfo* qPtr;
}queue;

queue initQueue()
{
    queue q;
    q.qPtr = malloc(sizeof(qinfo));
    q.qPtr->size=0;
    q.qPtr->head = q.qPtr->tail=NULL;
    return q;
}

int enqueue(queue p, node* h)
{

    h = malloc(sizeof(node));
    if(h==NULL)
    {
        printf("malloc failed");
        return 1;
    }
    h->data = 24;
    h->next = NULL;

    if (p.qPtr->tail == NULL)
    {
        p.qPtr->head = p.qPtr->tail = h;
        p.qPtr->size++;
    }
    else
    {
        p.qPtr->tail->next= h;
        p.qPtr->tail=h;
        p.qPtr->size++;
    }

    return 0;

}

node* dequeue(queue h)
{
    node* p = h.qPtr->head;
    h.qPtr->head = p->next;
    printf("%d was dequeued\n", p->data);
    h.qPtr->size--;
    return p;
}
void printList(queue q)
{


    node* temp = q.qPtr->head;
    while (temp != NULL)
    {
    printf(" %d ", temp->data);
    temp = temp->next;

    }

}
void freeList(queue q)
{
   node*temp = q.qPtr->head;
   int i=0;
    while(temp != NULL)
    {
        node *new_head = temp->next;
        i++;
        free(temp);
        temp = new_head;
    }
    free(q.qPtr);
    printf("\nfreed %d times\n", i);

}

node *initNode(){
  return NULL;
}

int getSize(queue q)
{
    printf("\nsize is: %d", q.qPtr->size);
    return q.qPtr->size;
}
int main(void)
{
    queue test;
    test = initQueue();
    node* h=initNode();
    enqueue(test,h);
    enqueue(test,h);
    enqueue(test,h);
    dequeue(test);
    printf("Queue:");
    printList(test);
    getSize(test);
    freeList(test);

    return 0;
}
