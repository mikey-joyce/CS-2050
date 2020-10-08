#include<stdlib.h>
#include<stdio.h>

int addition(int arr[], int size){
	//for loop to traverse the array
	int total=0;
	for(int i=0; i<size; i++){
		//adds whatever is in the array[i] to the total
		total += arr[i];
	}
	
	return total;
}

int main(void){
	int size = 5;
	int array[5]={5,10,8,2,13};

	//prints whatever is in array, even if array is different from one above
	printf("Array is: ");
	for(int i=0; i<size; i++){
		if(i==size){
			printf("%d", array[i]);
		}
		printf("%d, ", array[i]);
	}

	//prints and finds the sum of array
	printf("\nSum is: %d\n", addition(array, size));

	return 0;
}

