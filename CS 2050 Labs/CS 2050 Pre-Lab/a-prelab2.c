#include <stdio.h>

int compareIntegers(int arr[], int size, int val, int *lower, int *higher);

int main(void){
	int low, high, compare;
	int size=0;
	low=high=compare=0;
	
	printf("Enter the size of array: ");
	scanf("%d", &size);

	int array[size];
	printf("Enter array values: \n");
	for(int i=0; i<size; i++){
		scanf("%d", &array[i]);
		//printf("\n"); 
	}
	
	printf("Enter comparison value: \n");
	scanf("%d", &compare);
	
	compareIntegers(array, size, compare, &low, &high);
	printf("Amount lower: %d\n", low);
	printf("Amount higher: %d\n", high);
	return 0;
}

int compareIntegers(int arr[], int size, int val, int *lower, int *higher){
	//Compares val to arr[] and determines if it is greater or less-than
	for(int i=0; i<size; i++){
		if(arr[i]==val){
			continue;
		}
		else if(arr[i]>val){
			*higher+=1;
			continue;
		}
		else{
			*lower+=1;
		}
	}
	return 0;
}
