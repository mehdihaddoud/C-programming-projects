/*****************
* FILENAME : PlayWithYourName.c
*
* DESCRIPTION : The programs asks the user to enter his first and last names. The program shows the positions of all the letters in each name and then, reverts the names
* and then makes a string that combines each names.
*
* AUTHOR :    Mehdi Haddoud    START DATE :    7 July 2021
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char* revert_string(char* s);

int main(int argc, char const *argv[]) {

  char input[100];

  printf("Enter the first name :\n");

  scanf("%s",input);

  char* firstName = input;

  printf("You entered : %s\n", firstName);

  printf("Here are the positions of all the letters in the name %s.\n", firstName);

  for(int i = 0; i < strlen(firstName); i++)
    printf("Position : %d\tLetter:%c\n", i,firstName[i]);


   char* reverted = revert_string(firstName);

  printf("The reverted string is: : %s\n", reverted);

  printf("Enter the last name : \n");

  char new_input[100];

  scanf("%s", new_input);

  char* lastName = new_input;

  printf("You entered : %s\n", lastName);

  for(int i = 0; i < strlen(lastName); i++)
    printf("Position : %d\tLetter:%c\n", i,lastName[i]);

  char* last_name_reverted = revert_string(lastName);

   printf("The reverted string is: : %s\n", last_name_reverted);

  char fullName[strlen(firstName) + strlen(lastName) + 1];

  strcpy(fullName,firstName);

  strcat(fullName, " ");

  strcat(fullName,lastName);

  printf("Full name is : %s\n", fullName);

  return 0;
}

char* revert_string(char* s){

  int N = strlen(s);

  char* reverted;

  for(int i = 0; i <= N;i++)
      reverted[i] = s[N-1 - i];

  return reverted;

}
