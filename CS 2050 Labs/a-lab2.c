#include<stdio.h>
#include<stdlib.h>

void countGrades(int arr[], int size, int BBoundary, int CBoundary, int *NoOfAs, int *NoOfBs, int *NoOfCs);

int main(void){
	int array[30] = {57,99,53,58,46,46,92,72,43,82,42,90,70,65,88,53,59,75,43,45,66,69,63,93,77,98,99,40,88,49};
	int size = sizeof(array)/sizeof(array[0]);
	int BBoundary = 80, CBoundary = 60;
	int a=0, b=0, c=0;

	countGrades(array, size, BBoundary, CBoundary, &a, &b, &c);
	printf("A's: %d\nB's: %d\nC's: %d\n", a, b, c);
	
	return 0;
}

void countGrades(int arr[], int size, int BBoundary, int CBoundary, int *NoOfAs, int *NoOfBs, int *NoOfCs){
	//for loop goes through the array
	for(int i=0; i<size; i++){
		//checks to see if array[i] is an A grade, if so continue
		if(arr[i]>=BBoundary){
			*NoOfAs += 1;
			continue;
		}
		//checks to see if array[i] is a B grade, if so continue
		else if(arr[i]>=CBoundary){
			*NoOfBs += 1;
			continue;
		}
		//default value if grade is not A or B then it is C
		else{
			*NoOfCs += 1;
		}
	}
}
