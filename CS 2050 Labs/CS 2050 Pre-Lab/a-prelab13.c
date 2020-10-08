#include <stdio.h>
#include <stdlib.h>

//returns negative number if a is less than b
//returns positive number if a is greater than b
//returns 0 if a is equal to b
int compare(void *a, void *b);
int binarySearch(void *array[], int first, int last, void *query);

/*Sample main function*/
int main(void){
  int myArray[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int result;
  int query=6;

  printf("You want to search for the number 6\n");
  result=binarySearch((void *)myArray, 0, 9, (void *)&query);

  printf("The result location was: array[%d]\n", result);
}

int compare(void *a, void *b){
  //compares a and b using subtraction
  return (*(int *)a - *(int *)b);
}

/*Currently this returns the location in the array of the target
element*/
int binarySearch(void *array[], int first, int last, void *query){
  //If the array is empty
  if(first>last){
    //No values in the array
    //An index that is not possible is returned
    return -1;
  }

  //Finds the middle element of the array
  int mid=(first+last)/2;
  int result = compare(query, &((int *)array)[mid]);

  //if target element is less than the middle element
  if(result<0){
    //then return the first half of the array
    return binarySearch(array, first, mid-1, query);
  }
  //if target element is greater than the middle element
  else if(result>0){
    //then return the last half of the array
    return binarySearch(array, mid+1, last, query);
  }
  //if target element is equal to the middle element
  else{
    //return the location of the middle element
    return mid;
  }
}
