/*********************************************************************
* FILENAME : image.c
*
* DESCRIPTION : This code returns a matrix of pixels containing random shades of red green and blue
*
* AUTHOR :    Mehdi       START DATE :    10 july 2021
*
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define nbLines 10

#define nbColumns 10

struct Pixel {
  uint8_t R,G,B;
};

struct Image{

  struct Pixel* matrix[nbLines];

};

void returnRandomImage(struct Image* image){

  srand(time(NULL));

  int lower = 0, upper = 255;

  for(int i = 0; i < nbLines; i++){

    image->matrix[i] = (struct Pixel*)malloc(nbColumns*sizeof(struct Pixel));

    for(int j = 0; j < nbColumns ;j++){

      image->matrix[i][j].R = (rand() % (upper - lower + 1)) + lower;

      image->matrix[i][j].G = (rand() % (upper - lower + 1)) + lower;

      image->matrix[i][j].B = (rand() % (upper - lower + 1)) + lower;

    }
    }

}

void printMatrix(struct Image* image){

  for(int i = 0; i < nbLines; i++){

    for(int j = 0; j < nbColumns;j++){

      printf("(%d,%d,%d) ",image->matrix[i][j].R,image->matrix[i][j].G,image->matrix[i][j].B);

}
  printf("\n");
}
}

int main(int argc, char const *argv[]) {

  struct Image image;

  returnRandomImage(&image);

  printMatrix(&image);

  for (int i = 0; i <nbLines;i++){
    free(image.matrix[i]);
  }

  return 0;
}
