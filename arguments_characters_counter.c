/*H**********************************************************************
* FILENAME :        arguments_characters_counter.c
*
* DESCRIPTION : This code gives the number of characters for each argument entered in the command line.
*
* AUTHOR :    Mehdi       START DATE :    22 july 2021
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]) {

  int j = 0;

  if(argc == 1)
  {

    printf("No argument entered!\n");

  }
  else
  {
    for(int i = 1; i <argc; i++)
    {

      printf("Argument number %d has %lu characters.\n",i,strlen(argv[i]));

    }
  }
  return 0;
}
