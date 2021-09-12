// This programs swap the content of two arrays between each other.
// Author : Mehdi Haddoud
// Date : July 9, 2020

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_ARRAY 20

void swapArrays(int* arrayA,int* arrayB, int size){

  int temp[size];

  for(int i = 0; i < size; i++){

    temp[i] = arrayA[i];

    arrayA[i] = arrayB[i];

    arrayB[i] = temp[i];

  }

}

int main(int argc, char const *argv[]) {

  srand(time(NULL));

  int A[SIZE_ARRAY],B[SIZE_ARRAY];

  int lower = -100, upper = 100;

  int number;

  for(int i = 0; i < SIZE_ARRAY;i++){

    number = (rand() % (upper - lower + 1)) + lower;

    A[i] = number;

  }

  for(int i = 0; i < SIZE_ARRAY;i++){

    number = (rand() % (upper - lower + 1)) + lower;

    B[i] = number;

  }

  printf("A\tB\n");

  for(int i = 0 ; i < SIZE_ARRAY; i++)
    printf("%d\t%d\n",A[i],B[i]);

  swapArrays(A,B,SIZE_ARRAY);

  printf("-----------------------------------\n");

  printf("A\tB\n");

  for(int i = 0 ; i < SIZE_ARRAY; i++)
    printf("%d\t%d\n",A[i],B[i]);

  return 0;
}
