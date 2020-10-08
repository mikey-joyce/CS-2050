#include <stdio.h>
#include <stdlib.h>

//struct that holds the row and columns of the array
typedef struct
{
    float rows, columns;
} TableDimensions;

//Function prototypes
void **create2DArray(int numRows, int numCols, int elemSize);
float getRowSize(void **table);
float getColSize(void **table, int rowNo);
void printTable(void **table);
void freeTable(void **table);

/*This function creates an array of any type with an extra spot in front for
the TableDimensions struct. The struct holds the number of rows for the array and
the number of columns for the array.
Input:
	int rows: number of Rows
	int columns: number of columns
	int elementSize: number of elements
Output:
	void** table: output array that is created by the function*/
void ** create2DArray(int rows, int columns, int elementSize)
{
    void ** table = malloc(rows * sizeof(void *));
    *table = malloc(columns * elementSize + sizeof(TableDimensions));
    for(int i = 1; i<rows; i++)
    {
        *(table + i) = malloc(columns * elementSize);
    }
    TableDimensions test = {rows, columns};
    **((TableDimensions **)table) = test;
    *table += sizeof(TableDimensions);

    return (void **)table;
}

/*This function takes a void array and returns the rows retreived from the TableDimensions struct
stored before the array.
Input:
	void** table: void pointer input array
Output:
	rows: number of rows derived from TableDimensions struct stored before the array.*/
float getRowSize(void ** table)
{
    return ((TableDimensions *)((*table) - sizeof(TableDimensions)))->rows;
}

/*This function takes a void array and returns the columns retreived from the TableDimensions struct
stored before the array.
Input:
	void** table: void pointer input array
Output:
	columns: number of columns derived from TableDimensions struct stored before the array.*/
float getColSize(void ** table, int rowNo)
{
    return ((TableDimensions *)((*table) - sizeof(TableDimensions)))->columns;
}

/*This function frees all memory allocated to said array from the create2DArray function.
Input:
	void** table: input array
Output:
	none*/
void freeTable(void ** table)
{
		for(int i=0; i<getRowSize(table); i++){
			free(table[i]);
		}
		free(table-1);
}

/*This function takes a void pointer 2d array and prints out the values of each element
Input:
	void **table: input array
Output:
	none: but it does print out the value of each element of the array*/
void printTable(void **table){
	// Initialize array values and print them at the same time
	for(int i = 0; i<getRowSize((void **)table); i++)
	{
			for(int j = 0; j<getColSize((void **)table,0); j++)
			{
					printf("%d\t", (((int**)table)[i][j]));
			}
			puts("");
	}

}

int main(void)
{
    int rows = 10, columns = 10;
    int ** table = (int **)create2DArray(rows, columns, sizeof(int));
    printf("The array values are:\n");

    // Initialize array values
    int counter = 0;
    for(int i = 0; i<getRowSize((void **)table); i++)
    {
        for(int j = 0; j<getColSize((void **)table,0); j++)
        {
            counter++;
            table[i][j] = counter;
        }
    }

		//Proves that getRowSize and getColSize work properly
		printf("Row size: %f\n", getRowSize((void**)table));
		printf("Col size: %f\n", getColSize((void**)table,0));
		printTable((void**)table);

    freeTable((void **)table);

    puts("Program has finished.");
    return 0;
}
