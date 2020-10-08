#include <stdio.h>
#include <stdlib.h>

//ADT struct
typedef struct nodestruct {
    int key;
    struct nodestruct * next;
} Node;

//info struct
typedef struct liststruct {
    int size;
    Node * head;
    Node * tail;
} List;

//prototypes
List * createList();
void freeList(List *);
int getListLength(List *);
void printList(List *);
int insertAtHead(int, List *);
int insertAtTail(int, List *);
List * copyList(List *);


//main
//various testing - ignore
int main(void)
{
    int i;
    List * nums = createList();

    if(nums)
    {
        printf("Empty Size: %d\n", getListLength(nums));
        printList(nums);

        for(i = 0; i < 5; i++)
        {
            if(!insertAtHead(2*i, nums))
            {
                printf("Failed to insert..\n");
                break;
            }
        }

        printf("Heads Size: %d\n", getListLength(nums));
        printList(nums);

        for(i = 0; i < 5; i++)
        {
            if(!insertAtTail(-2*i, nums))
            {
                printf("Failed to insert..\n");
                break;
            }
        }

        printf("Tails Size: %d\n", getListLength(nums));
        printList(nums);

        List * nums2 = copyList(nums);

        if(nums2)
        {
            printf("Copy Size: %d\n", getListLength(nums2));
            printList(nums2);

            freeList(nums2);
        }

        freeList(nums);
    }

    printf("Success.\n");
    return 0;
}

//creates a new empty list
//returns the new list or NULL in the case of malloc failure
List * createList()
{
    List * new = (List *)malloc(sizeof(List));

    if(new) //check malloc
    {
        new->size = 0;
        new->head = NULL;
        new->tail = NULL;
    }

    return new;
}

void freeList(List * list)
{
    Node * temp = list->head;

    //free the allocated memory
    while(temp != NULL)
    {
        list->head = temp->next;
        free(temp);
        temp = list->head;
    }

    free(list);

    //exit
    return;
}

//gets the size of a given list
//takes in a list and returns it's size
int getListLength(List * list)
{
    //return size
    return list->size;
}

//print the contents of a list
//takes in a list and returns nothing
void printList(List * list)
{
    if(getListLength(list) == 0) //check if list is empty
        printf("The list is empty.\n");
    else
    {
        Node * temp = list->head;
        printf("List Values: ");

        //print all values but last one
        while(temp->next != NULL)
        {
            printf("%d, ", temp->key);
            temp = temp->next;
        }

        //print last value (formatting is different)
        printf("%d\n", temp->key);
    }

    //exit
    return;
}

//inserts a value at the head of a linked list
//takes in an int to insert and a list to put it into
//returns 1 if successful and 0 if not
int insertAtHead(int num, List * list)
{
    Node * new = (Node *)malloc(sizeof(Node));

    if(new) //check malloc
    {
        //new data
        new->key = num;
        new->next = list->head;
        list->head = new;

        //if the list is empty, make sure the tail still gets set
        if(getListLength(list) == 0)
            list->tail = new;

        //increase size
        (list->size)++;
        return 1; //success
    }
    else
        return 0; //error
}

//inserts a value at the tail of a list
//takes in an int to insert and a list to put it into
//returns 1 if successful and 0 if not
int insertAtTail(int num, List * list)
{
    Node * new = (Node *)malloc(sizeof(Node));

        if(new) //check malloc
        {
            //new data
            new->key = num;
            new->next = NULL;

            //if the list is empty, make sure the head still gets set
            //if not, make sure the old tail's next gets set to the new data
            if(getListLength(list) == 0)
                list->head = new;
            else
                list->tail->next = new;

            list->tail = new;

            //increase size
            (list->size)++;

            return 1; //success
        }
        else
            return 0; //error
}

//copys the entirety of a list
//takes in a list and returns a copy of that list
List * copyList(List * list)
{
    int i;
    List * new = createList();
    Node * temp = list->head;

    if(new) //check malloc
    {
        //go through whole list and add to the end of the new list
        for(i = 0; i < getListLength(list); i++)
        {
            //if malloc fails at any point, free everything copied
            if(!insertAtTail(temp->key, new))
            {
                temp = new->head;

                while(temp != NULL)
                {
                    new->head = temp->next;
                    free(temp);
                    temp = new->head;
                }

                free(new);

                return NULL;
            }

            temp = temp->next;
        }
    }

    //return copied list
    return new;
}
