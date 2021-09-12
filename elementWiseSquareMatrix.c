/*****************
* FILENAME : elementWiseSquareMatrix.c
*
* DESCRIPTION : This program asks the user to enter a Matrix and return the
* the elementWise squared matrix
*
* AUTHOR :    Mehdi Haddoud       START DATE :    5 July 2021
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void generateMatrix(int** mat,int nbLines, int nbColumns){

  int entry;

  for(int i = 0; i < nbLines ;i++)
    for(int j = 0; j < nbColumns;j++){
      printf("A[%d][%d] = \n", i + 1,j + 1);
      scanf("%d", &entry);
      mat[i][j] = entry;
    }

}
//
void printMatrix(int** mat, int nbLines, int nbColumns){

  for(int i = 0; i < nbLines; i++){
    for(int j = 0; j < nbColumns;j++)
      printf("%d ", mat[i][j]);

    printf("\n");
  }
}

void elementWisePowerSquare(int** mat, int nbLines, int nbColumns){
  for(int i = 0; i < nbLines; i++)
    for(int j = 0; j < nbColumns;j++)
      mat[i][j] = pow(mat[i][j], 2);
}

int main(int argc, char const *argv[]) {

  int nbRows, nbColumns;

  printf("Enter the number of rows : \n");

  scanf("%d", &nbRows);

  printf("Enter the number of columns: \n");

  scanf("%d", &nbColumns);

  printf("\n");

  int** mat;

  mat = (int**)malloc(nbRows * sizeof(int*));

  for (int i=0; i<nbRows; i++)
       mat[i] = (int *)malloc(nbColumns * sizeof(int));


  generateMatrix(mat, nbRows,nbColumns);
  printf("Here is what you entered : \n");
  printMatrix(mat, nbRows, nbColumns);

  elementWisePowerSquare(mat, nbRows , nbColumns);

  printf("----------------------------------\n");

  printf("Elementwise square Matrix : \n");

  printMatrix(mat, nbRows, nbColumns);

  for (int i=0; i<nbRows; i++)
       free(mat[i]);

  free(mat);

  return 0;

}
