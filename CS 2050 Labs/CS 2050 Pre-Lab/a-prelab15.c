/*This is the file for pre-lab #15
Created by: Mikey Joyce*/
#include <stdlib.h>
#include <stdio.h>

typedef struct treeStruct
{
    int data;
    struct treeStruct *left;
    struct treeStruct *right;
}Tree;

//prototypes
Tree *createNode(int);
Tree *insertBST(Tree *, int);
Tree *searchBST(Tree *, int );
void printTree(Tree *);
void freeTree(Tree *);

//test my library
int main(void)
{
    Tree *mainRoot = NULL;
    Tree *searchResult = NULL;

    //tests the insert function
    mainRoot = insertBST(mainRoot, 50);
    insertBST(mainRoot, 30);
    insertBST(mainRoot, 20);
    insertBST(mainRoot, 40);
    insertBST(mainRoot, 17);

    //tests the search function
    searchResult = searchBST(mainRoot, 20);
    printf("Search result: %d\n", searchResult->data);

    //tests print function
    printTree(mainRoot);
    printf("DONE\n");

    //tests free function
    freeTree(mainRoot);

    //Everything was successful as of 5/5/2020 at 7:03PM CST
    return 0;
}

/*This function creates a node of type Tree. Every value within node is initialized.
Input:
  int data;
Output:
  Tree myTree;*/
Tree *createNode(int data){
  //allocate memory for the tree
  Tree *myTree=malloc(sizeof(Tree));

  //check malloc
  if(myTree==NULL){
    //malloc failed
    return NULL;
  }

  //initialize data
  myTree->data=data;

  //initialize left and right to NULL
  myTree->left=NULL;
  myTree->right=NULL;

  //node is created, so return the tree
  return myTree;
}

/*This function inserts a node in a tree based on the given key.
Input:
  Tree *root;
  int data;
Output:
  none;*/
Tree *insertBST(Tree *root, int key){
  //NULL check root
  if(root==NULL){
    //root doesn't exist so create a new node
    return createNode(key);
  }
    //if key is less than current root
    if(key < root->data){
      //go down left side of tree
      root->left = insertBST(root->left, key);
    }
    //if key is greater than current root
    else{
      //go down right side of tree
      root->right = insertBST(root->right, key);
    }
    //location found: return root
    return root;
}

/*This function searches for a node in a tree based on the given key.
Input:
  Tree *root;
  int key;
Output:
  //current root
  Tree *root;*/
Tree *searchBST(Tree *root, int key){
  //base case
  //if root doesn't exist or root is the same as key
  if(root==NULL || root->data==key){
    //return root
    return root;
  }
  //if root is less than key
  else if(root->data < key){
    //return nodes greater than root
    return searchBST(root->right, key);
  }
  //if root is greater than key
  else{
    //return nodes less than root
    return searchBST(root->left, key);
  }

  //insertBST failed
  return NULL;
}

/*This function prints all nodes in a tree from left to right.
Input:
  Tree *root;
Output:
  none;*/
void printTree(Tree *root){
  //NULL check root, acts as base case
  if(root!=NULL){
    //print all nodes left of root
    printTree(root->left);

    //print root
    printf(" %d -->", root->data);

    //print all nodes right of root
    printTree(root->right);
  }
  //if root doesn't exist exit the function
  else{
    return;
  }
}

/*This function frees all memory allocated to the tree.
Input:
  Tree *root;
Output:
  none;*/
void freeTree(Tree *root){
  //base case
  //if root doesn't exist exit the function
  if(root==NULL){
    return;
  }

  //free all memory left of the root
  freeTree(root->left);

  //free all memory right of the root
  freeTree(root->right);

  //free the root
  free(root);
}
