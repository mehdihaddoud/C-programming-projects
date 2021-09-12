//Author : Mehdi Haddoud
//Date : July 15, 2021
//Description : Programs that check the user input. If the input is an integer,
//the value of the input is added to an array. The user can add as many integers as desired.
//If the user type "end", the programs ends and it displays all the entries.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DIGITS 18
#define MIN_SIZE 5
#define BUFSIZE (DIGITS) + 3

int main(int argc, char const *argv[]) {

  printf("Add as many integers as you want! In the end, all your entries will displayed.\n");

  int i = 0;

  char no_entry[2] = {'\n','\0'};

  long long int* array = (long long int*)malloc(MIN_SIZE * sizeof(int));

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

              exit(0);
            }

            printf("Not a valid integer!\nRestart (type \"end\" to quit):");

          }
      }

      }
    }


  }

  return 0;
}
