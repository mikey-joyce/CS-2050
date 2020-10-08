#include<stdio.h>
#include<stdlib.h>

int *readIntIntoArray(FILE* fp, int* totalNumOfEmployee, float* averageAge);
void findMinMax(int* arr, int size, int* minAge, int* maxAge);
void freeIntArray(int** arrPtr);

int main(void){
	FILE *fptr;
	int *arr;
	int total=0;
	int minAge=0;
	int maxAge=0;
	float average=0.0;
	
	if((fptr = fopen("employeeAge.txt", "r"))){
		printf("File open success\n");
	}
	else{
		perror("Error opening file\n");
	}
	
	//Computes the array, size of array, and average age
	arr=readIntIntoArray(fptr, &total, &average);
		
	//Computes min and max ages
	findMinMax(arr, total, &minAge, &maxAge);
	
	//Prints out average, min, and max ages
	printf("Average Age: %f\nMin Age: %d\nMax Age: %d\n", average, minAge, maxAge);

	//frees memory
	freeIntArray(&arr);
	return 0;
}

int *readIntIntoArray(FILE* fp, int* totalNumOfEmployee, float* averageAge){
	//Reads total number of employees and declares array
	*totalNumOfEmployee=0;
	fscanf(fp, "%d", totalNumOfEmployee);
	int* arr;
	*averageAge=0;

	if((arr = malloc(((*totalNumOfEmployee)*sizeof(int))+sizeof(int)))){
		//Reads file, builds array, and returns it
		//Also gets average age ready to compute
		for(int i=0; i<*totalNumOfEmployee; i++){
			fscanf(fp, "%d", &arr[i]);
			*averageAge += arr[i];
		}
			
		//Computes the average age
		*averageAge=*averageAge / *totalNumOfEmployee;
		return arr;
	}
	else{
		//Malloc failed
		perror("Error with malloc\n");
		return NULL;
	}
}

void findMinMax(int* arr, int size, int* minAge, int* maxAge){
	//Set both to the first value of the array to start comparisons
	*minAge=arr[0];
	*maxAge=arr[0];

	//Compares each value in array to min and max if it is not the true min max val
	//Then set the new min max val
	for(int i=1; i<size; i++){
		if(*minAge>arr[i]){
			*minAge = arr[i];
		}
		else if(*maxAge<arr[i]){
			*maxAge = arr[i];
		}
	}
}

void freeIntArray(int** arrPtr){
	//Frees memory and sets array to NULL
	free(*arrPtr);
	arrPtr=NULL;
}
