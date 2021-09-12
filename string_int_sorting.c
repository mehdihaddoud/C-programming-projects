//Author : Mehdi Haddoud
//Date : july 16,2021
//Description : Algorithm that sorts user's inputs between int and strings.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DIGITS 18
#define MIN_SIZE 5
#define BUFSIZE (DIGITS) + 3
#define MAX_SIZE 100


int main(){

  FILE *fp;

  fp = fopen("/Users/mehdihaddoud/Documents/langage_C/test.txt","w+");

  char no_entry[2] = {'\n','\0'};

  char compare[5] = {'e','n','d','\n','\0'};

  long long int intArray[MAX_SIZE];

  char stringArray[MAX_SIZE][BUFSIZE];

  char input[BUFSIZE];

  char theString[BUFSIZE];

  int numberInt = 0;

  int N;

  int numberString = 0;

  int i = 0;

  char end = '\0';

  printf("Welcome to my sorting algorithm! Type anything you want and it will be sorted between integers and strings in a file that will appear on the same directory! (type \"end\" to quit at any time)\n");

  while(1){


    printf("> ");

    if(!fgets(input,sizeof(input),stdin)){

      exit(-1);

    }
    else {

      if(!strchr(input,'\n')){

        printf("Input too long! Restart (type \"end\" to quit) : ");

        while(fgets(input,sizeof(input),stdin) || !strchr(input,'\n'))

          printf("Input too long! Restart (type \"end\" to quit) : ");

      }
      else{

        if(!strcmp(input,no_entry)){

          printf("Not a valid input!\nRestart (type \"end\" to quit) : \n");

        }
        else{

          char* chk;

          long long int tmp = (int)strtol(input,&chk,10);

          if(isspace(*chk) || *chk == 0 || *chk == '.'){

            printf("You entered an integer : %lld\n",tmp);

            intArray[numberInt] = tmp;

            numberInt++;

          }
          else{

            if(!strcmp(input,compare)){

              int it = 0;

              fprintf(fp,"Integers :\tStrings:\n");

              while(it < numberInt || it < numberString){

                if(it < numberInt){

                  fprintf(fp,"%lld",intArray[it]);

                }

                fprintf(fp,"\t");

                if(it < numberString) {

                  fprintf(fp,"%s",stringArray[it]);

                }

                it++;

                fprintf(fp,"\n");

              }

              break;

            }

            N = 1;
            i = 0;

            do{

              N++;
              i++;

            }
            while(!(input[i] == '\0'));

            i = 0;

            while(i < N - 2){

              theString[i] = input[i];

              i++;
            }

            theString[N-2] = '\0';

            printf("You entered a string : \"%s\"\n",theString);

            strcpy(stringArray[numberString],theString);

            numberString++;

          }


        }

      }

    }

  }

  fclose(fp);

  return 0;

}
