#include<stdio.h>
#include<stdlib.h>

float * readFloatFileIntoArray(FILE *fptr, int *length);
int freeMem(float arr[]);

int main(void){
	FILE *fptr=NULL;
	int length=0;
	float *arr;
	
	//calls the function
	arr=readFloatFileIntoArray(fptr, &length);
	
	//tests if function worked
	for(int i=0; i<length; i++){
		printf("%f\n", *(arr+i));
	}
	
	freeMem(arr);	
	return 0;
}

int freeMem(float arr[]){
	//frees malloc and makes sure arr points to NULL
	free(arr);
	arr=NULL;
	return 0;
}

float * readFloatFileIntoArray(FILE *fptr, int *length){
	//This function reads a file to return an array of floats
	//opens file and checks to make sure no error occurred
	if((fptr = fopen("a-prelab3.txt", "r"))){
		//File properly opened
		printf("File open success\n");
		
		*length=0;
		fscanf(fptr, "%d", length);
		float *arr;
		
		//Dynamically allocates memory and checks to see if it didnt fail
		if((arr = malloc(((*length)*sizeof(float))+sizeof(int)))){
			//Reads the file and builds the array then returns it
			for(int i=0; i<*length; i++){
				fscanf(fptr, "%f", &arr[i]);
			}
			
			return arr;
		}
		else{
			//Malloc failed
			perror("Error with malloc");
			return NULL;
		}
	}
	else{
		//File opening failed
		perror("Error opening file");
		return NULL;
	}
}
