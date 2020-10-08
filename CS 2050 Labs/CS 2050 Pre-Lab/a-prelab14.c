#include<stdio.h>
#include<stdlib.h>

typedef struct empstruct{
    int SSN;
    int ID;
}Employee;

typedef struct empinfo{
    Employee* IDarray;
    Employee* SSNarray;
    int size;
}empDatabase;

empDatabase createSearchableEmployeeDB(Employee**, int);
Employee* findEmpBySSN(empDatabase, int);
Employee* findEmpByID(empDatabase,int);
void freeEmpDatabase(empDatabase);
void insertionSortID(Employee *, int);
void insertionSortSSN(Employee* , int);
int compare(const void * , const void *);
int binarySearchID(Employee* ,int , int , int);
int binarySearchSSN(Employee* ,int , int , int);

void insertionSortID(Employee* arr, int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i].ID;
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j].ID > key) {
            arr[j + 1].ID = arr[j].ID;
            j = j - 1;
        }
        arr[j + 1].ID = key;
    }
}

void insertionSortSSN(Employee* arr, int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i].SSN;
        j = i - 1;


        while (j >= 0 && arr[j].SSN > key) {
            arr[j + 1].SSN = arr[j].SSN;
            j = j - 1;
        }
        arr[j + 1].SSN = key;
    }
}

int compare (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

empDatabase createSearchableEmployeeDB(Employee** array, int size){
    empDatabase empDB;
    int i;

    empDB.size=size;
    empDB.IDarray = malloc(size*sizeof(Employee));
    empDB.SSNarray = malloc(size*sizeof(Employee));
    array = malloc(size * sizeof(Employee*));
  for(i=0;i<size;i++)
    {
        array[i] = malloc(sizeof(Employee));


    }
  for(i=0;i<size;i++)
      {
        array[i]->ID = 58-i;
      array[i]->SSN = 99-i;
    }

  for (i = 0; i < size; i++)
    {
       empDB.IDarray[i].ID = array[i]->ID;
       empDB.SSNarray[i].SSN = array[i]->SSN;
    }
    insertionSortID(empDB.IDarray, size);
    insertionSortSSN(empDB.SSNarray, size);

//qsort(empDB.IDarray,size,sizeof(Employee),compare);
//qsort(empDB.SSNarray->SSN,size,sizeof(int),compare);
  /*for (i = 0; i < size; i++)
    {
      printf("%d\n", empDB.IDarray[i].ID);
    }*/


    return empDB;
}

int binarySearchID(Employee* array,int first, int last, int x){
    if (first <= last) {
        int mid = (first+last) / 2;

        // If the element is present at the middle
        // itself
        if (array[mid].ID == x)
            return array[mid];

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (array[mid].ID > x)
            return binarySearchID(array, first, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearchID(array, mid + 1, last, x);
      }

    // We reach here when element is not
    // present in array
    return -1;
}

int binarySearchSSN(Employee* array,int first, int last, int x){
    if (first <= last) {
        int mid = (first+last) / 2;


        if (array[mid].SSN == x)
            return mid;


        if (array[mid].SSN > x)
            return binarySearchSSN(array, first, mid - 1, x);


        return binarySearchSSN(array, mid + 1, last, x);
}

    return -1;
}


Employee* findEmpByID(empDatabase empDB, int target){
  int x = binarySearchID(empDB.IDarray, 0, empDB.size, target);
  if (x==-1)
  {
    printf("\nEMPDNE\n");
    return NULL;
  }
  return (empDB.IDarray + x);
}

Employee* findEmpBySSN(empDatabase empDB, int target){
  int x = binarySearchSSN(empDB.SSNarray,0,empDB.size,target);
  if (x==-1)
  {
    printf("\nEMPDNE\n");
    return NULL;
  }
  return (empDB.SSNarray + x);
}


int main(void)
{
    Employee** array=NULL;
    //empDatabase empDB;
    empDatabase empDB =  createSearchableEmployeeDB(array,10);
    printf("%d\n", empDB.size);
    findEmpBySSN(empDB, 97);

}
