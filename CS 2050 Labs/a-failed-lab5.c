#include<stdio.h>
#include<stdlib.h>

void **create2DArray(int numRows, int numCols, int elemSize);
float getRowSize(void **table);
float getColSize(void **table, int rowNo);
void printTable(void **table, int rows, int cols);
void freeTable(void **table);

void **create2DArray(int numRows, int numCols, int elemSize){
	printf("No seg fault: 1 create\n");
	void **table=(void**)malloc(numRows*sizeof(void*));
	printf("No seg fault: 2 create\n");
	*table=malloc((numCols*elemSize)+(2*sizeof(float)));
	for(int i=1; i<numRows; i++){
		*(table+i)=(void**)malloc((numCols*elemSize)+sizeof(float));
		*((int*)(table+i))=(float)numCols;
		table+=sizeof(float);
	}
	printf("No seg fault: 3 create\n");
	*((int**)table)=&numRows;

	*table+=(2*sizeof(float));
	printf("No seg fault: 4 create\n");
	return(void**)(table);
}

float getRowSize(void **table){
	float i=0.0;
	return i;
}

float getColSize(void **table, int rowNo){
	float i=0.0;
	return i;
}

void printTable(void **table, int rows, int cols){
	printf("No seg fault: 1 print\n");
	int counter=0;
	int **otherTable=(int**)table;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			counter++;
			printf("No seg fault: i=%d, j=%d print\n", i, j);
			otherTable[i][j]=0;
			printf("No seg fault: 2 printf\n");
			int w=otherTable[i][j];
			printf("%d\t", w);
		}
	}
	printf("No seg fault: 3 print\n");
}

void freeTable(void **table){

}

int main(void){
	printf("No seg fault: 1 main\n");
	int **table=(int**)create2DArray(10, 10, sizeof(int));
	printf("No seg fault: 2 main\n");
	printTable((void**)table, 10, 10);

	return 0;
}
