/*File for Lab #15
Created by: Mikey Joyce*/

#include "lab15.h"

//custom prototypes
Node *createNode(Employee *);

/*This function takes a FILE pointer and reads in every line of FILE fptr.
It uses this to create an array of pointers to a struct. After the function is finished
it returns Employee **myArray that is properly populated.
Input:
  FILE *fptr;
Output:
  Employee **myArray;*/
Employee ** readRecord(FILE *fptr){
  //Create my array of Students, opens file and gets the size of file.
  Employee **myArray;
  int size;
  fptr = fopen("employee.csv", "r");

  //Checks if file opened properly
  if(!fptr){
    //file opening failed
    return NULL;
  }

  //get size
  fscanf(fptr, "%d\n", &size);

  //Allocate memory to my array
  myArray = malloc(size * sizeof(Employee *));

  //Checks if malloc worked
  if(!myArray){
    //malloc failed
    return NULL;
  }

  //Runs through the file until the end of file is reached
  while(!feof(fptr)){
    for(int i=0; i<size; i++){
      //mallocs all Students
      myArray[i] = malloc(sizeof(Employee));

      //Checks if malloc worked
      if(!myArray[i]){
        //malloc failed
        return NULL;
      }

      //Scans in from the file
      fscanf(fptr, "%d,%f,%d\n", &myArray[i]->ID, &myArray[i]->salary, &myArray[i]->ssn);
    }
  }

  //closes file
  fclose(fptr);

  return myArray;
}

/*This function receives two pointrs to employee structs as void pointers. It
then compares the values of the SSNs withing the Employee structs. If the first
is larger than the second 1 is returned. If the second is larger than the first
-1 is returned. If they are equal 0 is returned.
Input:
  void *emp1;
  void *emp2;
Output:
  1;
  or
  -1;
  or
  0;*/
int comparison(void *emp1,void *emp2){
  //If first ssn is larger than second ssn
  if((((Employee *)(emp1))->ssn) > (((Employee *)(emp2))->ssn)){
    return 1;
  }
  //If first ssn is less than second ssn
  else if((((Employee *)(emp1))->ssn) < (((Employee *)(emp2))->ssn)){
    return -1;
  }

  //If the first ssn is equal to second ssn
  return 0;
}

/*This function takes a Node *currentRoot and Employee *emp. If the currentRoot
doesn't exist than a new node is created. If the currentRoot is greater than emp.
Then we go down the right side of the tree recursively. If the currentRoot is less
than emp. We go down the left side of the tree recursively. Once it reaches the end
the target location is reached and currentRoot is returned.
Input:
  Node *currentRoot;
  Employee *emp;
Output:
  Node *currentRoot;*/
Node* insertBST(Node *currentRoot, Employee *emp){
  //NULL check root
  if(currentRoot==NULL){
    //root doesn't exist so create a new node
    return createNode(emp);
  }

  //if current root is greater than key ssn
  if((comparison(currentRoot->data, emp))==1){
    //go down the right side of the tree
    currentRoot->right = insertBST(currentRoot->right, emp);
  }
  //if current root is less than key ssn
  else if((comparison(currentRoot->data, emp))==-1){
    //go down left side of the tree
    currentRoot->left = insertBST(currentRoot->left, emp);
  }

  //target location found
  return currentRoot;
}

/*This function takes a Node *currentRoot and int keySSN. If currentRoot is NULL
then the struct doesn't exist and NULL is returned. If currentRoot is equal to keySSN
then currentRoot is returned, this is the base case which will close the function (unless
the struct is equal to NULL). If currentRoot is less than keySSN we return the left side
of the tree. If currentRoot is greater than keySSN we return the right side of the tree.
Input:
  Node *currentRoot;
  int keySSN;
Output:
  Node *currentRoot;
  or
  if currentRoot is equal to NULL
    NULL;*/
Employee* searchBST(Node *currentRoot,int keySSN){
  //NULL check struct
  if(currentRoot==NULL){
    //struct doesn't exist
    return NULL;
  }

  //base case
  if(currentRoot->data->ssn==keySSN){
    //currentRoot is equal to keySSN so return currentRoot
    return currentRoot->data;
  }
  //if currentRoot is less than key
  else if(currentRoot->data->ssn < keySSN){
    //go up the left side of tree
    return searchBST(currentRoot->left, keySSN);
  }

  //if currentRoot is greater than key
  //go up right side of tree
  return searchBST(currentRoot->right, keySSN);
}

/*This function takes a Node *currentRoot and frees all memory
associated with currentRoot.
Input:
  Node *currentRoot;
Output:
  none;*/
void deleteTree(Node *currentRoot){
  //NULL check currentRoot
  if(currentRoot==NULL){
    //if currentRoot doesn't exist then exit function
    return;
  }

  //free left and right side of tree
  deleteTree(currentRoot->left);
  deleteTree(currentRoot->right);

  //frees the currentRoot
  free(currentRoot);
}

/*This function takes an Employee *emp as data. It then creates a new node in a
tree based on the data. The data, left, and right aspects of the tree are initialized.
At the end the tree is returned.
Input:
  Employee *emp;
Output:
  Node *myTree;*/
Node *createNode(Employee *emp){
  //allocate memory for the tree
  Node *myTree=malloc(sizeof(Node));

  //check malloc
  if(myTree==NULL){
    //malloc failed
    return NULL;
  }

  //initialize data
  myTree->data=emp;

  //initialize left and right to NULL
  myTree->left=NULL;
  myTree->right=NULL;

  //node is created, so return the tree
  return myTree;
}
