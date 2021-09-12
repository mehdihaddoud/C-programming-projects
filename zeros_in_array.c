/*****************
* FILENAME : zeros_in_array.c
*
* DESCRIPTION : This programs gives the number of zeros and their
* positions in an array inside a specific file.
*
*
* AUTHOR :    Mehdi Haddoud      START DATE :    13 July 2021
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 10000

extern int returnZeros(int* array, int size);

extern void addIndexes(int* index, int*array, int size);

int main(int argc, char const *argv[]) {

  char entry;

  printf("Hi! This programs gives you the number of zeros in an array.\n");
  printf("The array must be inside a file called \"array.txt\".\n");
  printf("The file must follow the format \"index : value\".\n");
  printf("The file must include a maximum of 10000 entries.\n");
  printf("Example :\n");
  printf("0 : 34\n");
  printf("1 : 0\n");
  printf("2 : 8\n");
  printf("...\n");
  printf("");
  printf("To continue press en enter.\n");
  scanf("%c",&entry);

  FILE* fptr;

  fptr = fopen("/Users/mehdihaddoud/Documents/langage_C/array.txt","r");

  if(fptr == NULL)
  {

     printf("Error! No file found!\n");

     exit(1);

  }

  else{

    printf("File found!\n\n");

    printf("Let's find out the number of zeros!\n");

    sleep(5);

    int i = 0, index_temp;

    int array[SIZE];

    char character;

    int numberOfZeros;

    while(!feof(fptr)){

      if(fscanf(fptr, "%c", &character) && character == ':'){

        fscanf(fptr, "%d", &array[i]);

        i++;

      }

      else

        fscanf(fptr, "%d", &index_temp);

    }

    int numberOfElements = i;

    numberOfZeros = returnZeros(array,numberOfElements);

    int index[numberOfZeros];

    addIndexes(array,index,numberOfElements);

    if(numberOfZeros == 0)

      printf("No zero found.\n");

    else if (numberOfZeros == 1)

      printf("There is only one zero and its position is : %d\n", *index);

    else{

      printf("The number of zeros is : %d and their positions are : \n", numberOfZeros);

      for(int i = 0; i < numberOfZeros; i++)

        printf("%d\n",*(index + i));
    }

    fclose(fptr);
    return 0;
  }
}

int returnZeros(int* array, int size){

    int j = 0;

    for(int i = 0; i < size; i++){

      if (!*(array + i)) {
        j++;
      }

    }

    return j;
}

void addIndexes(int* array, int* index, int size){
  int j = 0;
  for(int i = 0; i < size; i++){
    if(!*(array + i)){
      *(index + j) = i;
      j++;
    }
  }
}
