#include "lab14.h"

Student * binarySearch(Student** ,int , int , int);
void insertionSort(Student** , int);

/*This function takes a FILE pointer and reads in every line of FILE fptr.
It uses this to create an array of pointers to a struct. After the function is finished
it returns Student **myArray that is properly populated.
Input:
  FILE *fptr;
Output:
  Student **myArray;*/
Student ** readRecord(FILE *fptr){
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

/*This function takes Student **myArray and integer size as parameters. It then allocates memory
for the database. After this it sets the values passed in from the array to the database array.
An insertion sort is then applied to organize the database. At the end StudentDB myDatabase is returned.
Input:
  Student **myArray;
  int size;
Output:
  StudentDB myDatabase;*/
StudentDB createDatabase(Student **myArray, int size){
    StudentDB myDatabase;
    int i;

    //alias to the student array
    Student **myDBArray=myDatabase.array;

    //set size
    myDatabase.sizeOfDB=size;

    //allocate memory
    myDBArray = malloc(size*sizeof(Student*));

    //test if malloc worked
    if(!myDBArray){
      //malloc failed
      return myDatabase;
    }

    //allocate memory and set the values to be what was passed in
    for(i=0;i<size;i++){
        myDBArray[i] = malloc(sizeof(Student));
        myDBArray[i]->ID=myArray[i]->ID;
        myDBArray[i]->age=myArray[i]->age;
    }

    //sort the array
    insertionSort(myDBArray, size);

    //return the database
    return myDatabase;
}

/*This function takes StudentDB myDatabase and int data as parameters. It then calls
the binarySearch function which is a recursive function that returns the pointer to
the target item. If NULL is returned from binarySearch then the item didn't exist.
Input:
  StudentDB myDatabase;
  int data;
Output:
  returnVal;*/
Student * findStudentByID(StudentDB myDatabase, int data){
  //obtain the return value using binary search
  Student *returnVal = binarySearch(myDatabase.array, 0, myDatabase.sizeOfDB, data);

  //check if the returnVal exists
  if (returnVal==NULL){
    //Student doesn't exist
    return NULL;
  }

  //return what binarySearch gave us
  return returnVal;
}

/*This function takes StudentDB myDatabase as parameters. It frees all
allocated memory to this database.
Input:
  StudentDB myDatabase;
Output:
  none;*/
void freeDatabase(StudentDB myDatabase){
  //traverses database array
  for(int i=0; i<myDatabase.sizeOfDB; i++){
    //free allocated memory
    free(myDatabase.array[i]);
  }
  //free initial allocation
  free(myDatabase.array);
}

/*Here are my custom functions*/

/*This function implements the binarysearch algorithm. It takes
Student **myArray int first int last and int data as parameters. It is a
recursive function that will obtain the pointer to the target value
or will return NULL if it doesn't exist.
Input:
  Student **myArray;
  int first;
  int last;
  int data;
Output:
  Student *;*/
Student * binarySearch(Student ** myArray,int first, int last, int data){
    //utilizes the binary search algorithm

    if (first <= last) {
        int mid = (first+last) / 2;

        // If the element is present at the middle
        // itself
        if (myArray[mid]->ID == data)
            return myArray[mid];

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (myArray[mid]->ID > data)
            return binarySearch(myArray, first, mid - 1, data);

        // Else the element can only be present
        // in right subarray
        return binarySearch(myArray, mid + 1, last, data);
      }

    // We reach here when element is not
    // present in array
    return NULL;
}

/*This function implements the insertion sort algorithm. It takes
Student **array and int n as parameters and sorts the array.
Input:
  Student **array;
  int n;
Output:
  none;*/
void insertionSort(Student** array, int size)
{
    //utilizes insertion sort algorithm
    int val, j;
    for (int i = 1; i < size; i++)
    {
        val = array[i]->ID;
        j = i - 1;
        while (j >= 0 && array[j]->ID < val)
        {
            array[j + 1]->ID = array[j]->ID;
            j = j - 1;
        }
        array[j + 1]->ID = val;
    }
}
