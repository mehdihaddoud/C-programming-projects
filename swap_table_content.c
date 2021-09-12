/*****************
* FILENAME : swap_table_content.c
*
* DESCRIPTION : This program asks the user to enter as many integers as he/she desires. The program then swaps the order with which the user entered the integers and displays
* the content of the swapped array.
*
* AUTHOR :    Mehdi Haddoud    START DATE :    5 July 2021
*
*/


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define DIGITS 18
#define MIN_SIZE 5
#define BUFSIZE (DIGITS) + 3
#define ARRAY_SIZE 10

void takeEntry(long long int* array, int* totalEntries){

    printf("Add as many integers as you want! In the end, all your entries will displayed.\n");

    int i = 0;

    char no_entry[2] = {'\n','\0'};

    char compare[5] = {'e','n','d','\n','\0'};

    char input[BUFSIZE];

    long long int val;

    printf("Enter a value (type \"end\" to quit) :");

    while(1){

      if(!fgets(input,sizeof(input),stdin))

        exit(-1);

      else{

        if(!strchr(input,'\n')){ //if there is not '\n' in the input (input too long)

          printf("Input too long! Restart (type \"end\" to quit) :");

          while(fgets(input,sizeof(input),stdin) && !strchr(input,'\n'))
            printf("Input too long! Restart (type \"end\" to quit) :");

        }
        else{

          if(!strcmp(input,no_entry)){

            printf("Not a valid integer!\nRestart (type \"end\" to quit):");

          }
          else{

            char* chk;

            int tmp = (int) strtol(input,&chk,10);

            if(isspace(*chk) || *chk == 0){

              val = tmp;

              printf("\nYou added : %lld\n",val);

              array[i] = val;

              i++;

              printf("Number of entries : %d\n",i);

              printf("Enter a value (type \"end\" to quit) :");

            }
            else{

              if(!strcmp(input,compare)){

                printf("Here is what you entered : \n");

                int j = 0;

                for(j = 0; j < i;j++){

                  printf("%lld\n",array[j]);

                }

                printf("Total number of entries : %d\n", j);

                *totalEntries = j;

                break;

              }

              printf("Not a valid integer!\nRestart (type \"end\" to quit):");

            }
        }

        }
      }


    }


}

int* swap(long long int* array,int size){

  int temp[size];
  int* p = temp;
  for(int i = 0; i < size; i++)

    temp[size - 1 - i] = array[i];

  return p;

}

int main(int argc, char const *argv[]) {

  int totalEntries;

  long long int* array = (long long int*)malloc(MIN_SIZE * sizeof(int));

  takeEntry(array,&totalEntries);

  int* swapped;

  swapped = swap(array,totalEntries);

  for(int i = 0 ; i < totalEntries; i++)

    printf("swapped[%d] = %d\n",i,swapped[i]);

  return 0;
}
