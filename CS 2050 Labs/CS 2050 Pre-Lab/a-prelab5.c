#include<stdio.h>
#include<stdlib.h>

void **createTable(int rows, int cols, int dataSize);
int getRowSize(void **arr);
int getColSize(void **arr);
void freeArray(void **arr);

int main(void){
    printf("Code is working here: 1 main\n");
    float ** p = (float **)createTable(12,12,sizeof(float));
    int rows=0;
    int cols=0;

    printf("Code is working here: 2 main\n");
    rows=getRowSize((void**)p);
    cols=getColSize((void**)p);

    printf("Code is working here: 3 main\n");
    for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){
        p[i][j]=0.0;
        printf("%4f", p[i][j]);
      }
      printf("\n");
    }

    printf("Code is working here: 4 main\n");
    printf("Rows: %d\nColumns: %d\n", rows, cols);
}

void **createTable(int rows, int cols, int dataSize){
      printf("Code is working here: 1 table\n");
      int ** arr = (int **)malloc(sizeof(void *) * rows + 2 * sizeof(int));

      if(arr==NULL){
          printf("*** ERROR: Memory Allocation Failed ***\n");
          return NULL;
      }

      printf("Code is working here: 2 table\n");
      *(int *)arr = rows;
      printf("%d\n", *(int*)arr);
      *((int *)arr+1) = cols;
      printf("%d\n", *((int*)arr+1));

      printf("Code is working here: 3 table\n");
      for(int i = 0; i < rows; i++)
      {
          arr[i] = (int*)malloc(cols * dataSize);

          if (*(arr + i) == NULL)
          {
              printf("*** ERROR: Memory Allocation Failed ***\n");
              return NULL;
          }
      }

      printf("%d\n", *(int*)arr);
      printf("%d\n", *((int*)arr-1));
      printf("Code is working here: 4 table\n");

      return (void **)(arr+2);
}

int getRowSize(void **arr){
    return (*(int *)&arr[-2]);
}

int getColSize(void **arr){
    return (*(int *)(arr - 1));
}

void freeArray(void **arr){

}
