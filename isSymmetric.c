/*****************
* FILENAME : isSymmetric.c
*
* DESCRIPTION : This code takes as input a matrix and tells whether the matrix is symmetric or not
*
* AUTHOR :    Mehdi       START DATE :    13 july 2021
*
*/

#include <stdlib.h>
#include <stdio.h>

int isSymmetric(int** matrix, int rows, int columns){

for(int i = 0; i < rows ; i ++){
  for(int j = 0; j < columns; j++){
    if(matrix[i][j] != matrix[j][i])
      return 0;
  }
}
  return 1;

}

int main(int argc, char const *argv[]) {

  int rows, columns;

  printf("Enter the number of rows :\n");
  scanf("%d",&rows);
  printf("Enter the number of columns :\n");
  scanf("%d",&columns);


  int** matrix;

  matrix = (int**)malloc(rows * sizeof(int*));

  for (int i=0; i<rows; i++)
    matrix[i] = (int *)malloc(columns * sizeof(int));

  for(int i = 0; i < rows ;i++){
    for(int j = 0; j < columns ; j++){
      if(i != j)
        matrix[i][j] = 0;
      else
        matrix[i][i] = 0;
      }
    }

    int entry;

    printf("Enter the elements : \n");

    for (int i = 0 ; i < rows ; i++) {
      for (int j = 0 ; j < columns ; j++){
        printf("[%d][%d] :",i + 1 ,j + 1);
        scanf("%d", &entry);
        matrix[i][j] = entry;
      }
    }


  int result = isSymmetric(matrix,rows,columns);

  if (result == 1)

    printf("Matrix is symmetric.\n");

  if (result == 0)

    printf("Matrix is not symmetric.\n");

  return 0;
}
