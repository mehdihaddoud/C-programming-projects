/*****************
* FILENAME : math_exe.c
*
* DESCRIPTION : This is a small game that shows 10 basic random mathematical operations for the user to solve.
* One point for each right answer and minus one point for each wrong answer
*
* AUTHOR :    Mehdi       START DATE :    13 August 2021
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  srand(time(NULL));

  int result, iterator = 0;

  int point = 0;

  int input;

  int lower = 1, upper = 99;

  int lower_op = 0, upper_op = 3;

  int lower_mul = 1, upper_mul = 9;

  int number1, number2, nextOp;

  while (iterator < 10){

    nextOp = (rand() % (upper_op - lower_op + 1)) + lower_op;

    switch (nextOp){

      case 0 :

        number1 = (rand() % (upper - lower + 1)) + lower;

        number2 = (rand() % (upper - lower + 1)) + lower;

        result = number1 + number2;

        printf("%d + %d = ?\n",number1, number2);

        printf("Your answer : ");

        scanf("%d",&input);

        if (input == result){

          point++;

          printf("Right!\n");

          printf("Your points : %d\n",point);

          printf("------------------------------------\n");

        }

        else

        {

          point --;

          printf("Wrong! Right answer : %d\n",result);

          printf("Your points : %d\n",point);

          printf("------------------------------------\n");

        }
        iterator ++;
        break;

      case 1 :

        number1 = (rand() % (upper - lower + 1)) + lower;

        number2 = (rand() % (upper - lower + 1)) + lower;

        result = number1 - number2;

        printf("%d - %d = ?\n",number1, number2);

        printf("Your answer : ");

        scanf("%d",&input);

        if (input == result){

          point++;

          printf("Right!\n");

          printf("Your points : %d\n",point);

          printf("-----------------------------------\n");


        }

        else

        {

          point --;

          printf("Wrong! Right answer : %d\n",result);

          printf("Your points : %d\n",point);

          printf("------------------------------------\n");


        }
        iterator ++;
        break;

      case 2 :

        do {

        number1 = (rand() % (upper - lower + 1)) + lower;

        number2 = (rand() % (upper_mul - lower_mul + 1)) + lower_mul;

      } while(number1 * number2 == number1 || number1 * number2 == number2);

        result = number1 * number2;

        printf("%d * %d = ?\n",number1, number2);

        printf("Your answer : ");

        scanf("%d",&input);

        if (input == result){

          point++;

          printf("Right!\n");

          printf("Your points : %d\n",point);

          printf("------------------------------------\n");

        }

        else

        {

          point --;

          printf("Wrong! Right answer : %d\n",result);

          printf("Your points : %d\n",point);

          printf("------------------------------------\n");

        }
        iterator ++;
        break;

      case 3 :

      do{

          number1 = (rand() % (upper - lower + 1)) + lower;

          number2 = (rand() % (upper - lower + 1)) + lower;

        }while(number1 % number2 != 0 || number1/number2 == 1 || number1/number2 == number1);

        printf("%d / %d = ?\n",number1, number2);

        result = number1/number2;

        printf("Your answer : ");

        scanf("%d",&input);

        if (input == result){

          point++;

          printf("Right!\n");

          printf("Your points : %d\n",point);

          printf("------------------------------------\n");


        }

        else

        {

          point --;

          printf("Wrong! Right answer : %d\n", result);

          printf("Your points : %d\n",point);

          printf("------------------------------------\n");

        }
        iterator ++;
        break;


    }


}

  return 0;

}
