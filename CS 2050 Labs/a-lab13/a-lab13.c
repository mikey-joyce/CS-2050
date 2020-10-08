#include "lab13.h"

/*This function takes a FILE pointer and reads in every line of FILE fptr.
It uses this to create an array of pointers to a struct. After the function is finished
it returns Student **myArray that is properly populated.
Input:
  FILE *fptr;
Output:
  Student **myArray;*/
Student** readRecord(FILE *fptr){
  //Create my array of Students, opens file and gets the size of file.
  Student **myArray;
  int size;
  fptr = fopen("students.csv", "r");
  fscanf(fptr, "%d\n", &size);

  //Checks if file opened properly
  if(!fptr){
    //file opening failed
    return NULL;
  }

  //Allocate memory to my array
  myArray = malloc(size * sizeof(Student *));

  //Checks if malloc works
  if(!myArray){
    //malloc failed
    return NULL;
  }

  //Runs through the file until the end of file is reached
  while(!feof(fptr)){
    for(int i=0; i<size; i++){
      //mallocs all Students
      myArray[i] = malloc(sizeof(Student));

      //Checks if malloc worked
      if(!myArray[i]){
        //malloc failed
        return NULL;
      }

      //Scans in from the file
      fscanf(fptr, "%d,%d\n", &myArray[i]->age, &myArray[i]->ID);
    }
  }

  //closes file
  fclose(fptr);

  return myArray;
}

/*This function takes two void pointers as input. It then compares them using subtraction
and returns 1, -1, or 0. If 1 then result was greater than 0. If -1 then result was
less than 0. If 0 then result was equal to 0.
Input:
  void *a;
  void *b;
Output:
  1
  or
  -1
  or
  0*/
int comparison(void *a, void *b){
  //Compare a and b through subtraction
  int result = (((Student *)a)->ID) - abs((((Student *)b)->ID));
  //Returns the proper values
  if(result > 0)return 1;
  else if(result < 0)return -1;
  else return 0;
}

/*This function takes a void **array two integers and a void* query as input.
It then utilizes the recursive binary search algorithm to find the index of the
element we are looking for.
Input:
  void **array;
  int first;
  int last;
  void *query
Output:
  -1 (if failed)
  int mid (which respresents the index)

This function currently only returns -1 which doesn't make sense to me because it is exactly
how I did it on the prelab which worked properly.*/
int binarySearch(void **array, int first, int last, void *query){
  //If the array is empty
  if(first>last){
    //No values in the array
    //An index that is not possible is returned
    return -1;
  }

  //Finds the middle element of the array
  int mid=(first+last)/2;
  int result = comparison(query, &((void *)array)[mid]);

  //if target element is greater than the middle element
  if(result>0){
    //then return the first half of the array
    return binarySearch(array, first, mid-1, query);
  }
  //if target element is less than the middle element
  else if(result<0){
    //then return the last half of the array
    return binarySearch(array, mid+1, last, query);
  }
  //if target element is equal to the middle element
  else{
    //return the location of the middle element
    return mid;
  }

  //query value doesn't exist
  return -1;
}

/*This function takes void **array and int size as input. It then
traverses the given array and frees all allocated memory.
Input:
  Student **array;
  int size;
Ouput:
  none*/
void freeArr(Student **array, int size){
  //Traverses array
  for(int i=0; i<size; i++){
    //free allocated memory
    free(array[i]);
  }
  //free initial allocation
  free(array);
}
