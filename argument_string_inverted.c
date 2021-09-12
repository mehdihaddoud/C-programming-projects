/*H**********************************************************************
* FILENAME :        arguments_string_inverted.c
*
* DESCRIPTION : This code inverts all arguments given in the command line
*
* AUTHOR :    Mehdi       START DATE :    23 july 2021
*
*/
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int i = 1;

  if (argc >= 2)
  {
    if (argc == 2)
      printf("Inverted argument is :\n");
    else
      printf("Inverted arguments are :\n");

    while(i != argc){

      const int SIZE = strlen(argv[i]);

      char myString[SIZE];

      for(int j = 0 ; j < SIZE ; j++){

        myString[j] = (argv[i])[SIZE - 1 - j];

    }

    printf("%s\n", myString);

    i++;
  }

  }
  else
  {
    printf("Not enough argument.\n");
  }

  return 0;
}
