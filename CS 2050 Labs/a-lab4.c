#include<stdio.h>
#include<stdlib.h>

void* createArray(int n, int elemSize);
int getArraySize(void* array);
void freeArray(void* array);
void storeAve(void* array);

int main(void){
	int arraySize=10; //size of array
	void* arr=createArray(arraySize, sizeof(double));

	for(int i=0; i<arraySize; i++){
		*((double*)arr+i)=5.50+i;
		printf("arr[%d] = %f\n", i, *((double*)arr+i));
	}

	storeAve(arr);
	printf("Avg: %f\n", *((double*)&arr[-1]));
	
	int testSize=getArraySize(arr);
	printf("Size of array: %d\n", testSize);
		
	freeArray(arr);
	return 0;
}

/*This function receives an integer n and an integer elemSize as inputs. It then creates
an array of integers and allocates memory to said array based on the n amount of elements multiplied 
by the size of the data type in bytes (elemSize) + size of an integer in bytes and size of a double
in bytes. It then sets the first element of the array to the size n. It then sets the second element
of the array to a double value. It then returns the array as a void pointer and increments it by 2
so that the first and second element are "hidden".
Inputs:
	integer n: size of array
	integer elemSize: size of datatype in bytes
Outputs:
	void pointer: output array is incremented by 2*/
void* createArray(int n, int elemSize){
	void* arr;
	arr = malloc(((n)*elemSize)+sizeof(int)+sizeof(double));
	*((int*)arr)=n;
	*((double*)arr+1)=0.0;
	return (void*)(arr+2);
}

/*This function receives a void pointer array as input. It then returns the -2 element of the array,
which contains the size of the array.
Inputs:
	void* array: input array
Outputs:
	integer: size of the array*/
int getArraySize(void* array){
	int size=*((int*)&array[-2]);
	return size;
}

/*This function receives a void pointer array as input. It then frees all of the memory that was
allocated to it. After this is sets the array to NULL.
Inputs: 
	void* array: input array
Outputs:
	none*/
void freeArray(void* array){
	free(array-2);
	array=NULL;
	
}

/*This function receives a void pointer array. It then calls getArraySize to get the size of the
array and stores it as integer size. After this it declares a double called avg and initializes it as 
0.0. It then uses a for loop to traverse the array and add everything into avg. After this it
divides avg by the size to get the true average. Then it sets element -1 of array to the average.
Inputs:
	void pointer: input array
Outputs:
	none*/
void storeAve(void* array){
	int size=getArraySize(array);
	double avg=0.0;
	for(int i=0; i<size; i++){
		avg += *((double*)array+i);
	}
	avg = avg/size;
	*((double*)&array[-1])=avg;
}
