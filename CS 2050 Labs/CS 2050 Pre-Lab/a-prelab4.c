#include<stdio.h>
#include<stdlib.h>

void *createIntArray(int size, int dataSize);
int *getArraySize(int *arr);
void freeArray(int **arrPtr);

int main(void){
	int size1, size2, size3;
	size1=5;
	size2=7;
	size3=3;

	void* arr1;
	void* arr2;
	void* arr3;

	arr1=createIntArray(size1, sizeof(int));
	arr2=createIntArray(size2, sizeof(float));
	arr3=createIntArray(size3, sizeof(char));

	for(int i=0;i<size1;i++){
		*((int*)arr1+i)=i*2;
		printf("arr1[%d] = %d\n",i, *((int*)arr1+i));
	}	
	for(int i=0; i<size2; i++){
		*((float*)arr2+i)=(float)i*(float)2.4;
		printf("arr2[%d] = %f\n",i, *((float*)arr2+i));
	}
	for(int i=0; i<size3; i++){
		*((char*)arr3+i)='H';
		printf("arr3[%d] = %c\n",i, *((char*)arr3+i));
	}

	printf("Size of arrays: %d, %d, %d\n", *(getArraySize((int*)arr1)), *(getArraySize((int*)arr2)), *(getArraySize((int*)arr3)));
	
	freeArray(((int**)&arr1));
	freeArray(((int**)&arr2));
	freeArray(((int**)&arr3));	

	return 0;
}

void *createIntArray(int size, int dataSize){
	int* arr;
	arr = malloc(((size)*dataSize)+sizeof(int));
	arr[0]=size;
	return (void*)(arr+1);	
}

int *getArraySize(int *arr){
	return (&arr[-1]);
}

void freeArray(int **arrPtr){
	free(*arrPtr-1);
	*arrPtr=NULL;
}
