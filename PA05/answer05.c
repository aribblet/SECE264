#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

#include "answer05.h"
#define FOUR 4

Image * Image_loadbmp(constant char * filename);

int Image_savebmp(const char * filename, Image * image);

Image * Image_load(const char * filename)
{
  struct ImageHeader ImageHeader;
  FILE * fptr;
  int failure;
  unit32_t x;
  unit32_t y;
  unit32_t power;
  char * comment;
  char * memory;
  int w = ImageHeader.width;
  int h = ImageHeader.height;
  int wh = w * h;
  fptr = fopen(filename, "r");
  if (fptr == NULL){
      printf("fopen failed.\n");
      return NULL;}
  failure = fread(&ImageHeader, FOUR, FOUR, fptr);

  if(failure != FOUR) {
    printf("File does not contain 16 byte header. \n");
    return NULL;}

  if(ImageHeader.magic_number != ECE264_IMAGE_MAGIC_NUMBER){
    printf("The Magic Number did not match. \n");
    return NULL;}

  x = ImageHeader.width;
  if( x == 0) {
    printf("The width is 0. \n");
    return NULL;}

  y = ImageHeader.height;
  if(y == 0) {
    printf("the height is 0. \n");
    return NULL; }

  power = ImageHeader.comment_len;
  if(power == 0) {
    printf("There is no Comment. \n");
    return NULL; }

  comment = malloc(power);
  if(sizeof(comment) == 0){
    printf("comment malloc has failed.\n");
    return NULL;}

  memory = (char*)malloc(sizeof(char)*wh);
  if(memory == NULL) {
    printf("memory allocation for the image failed.\n");
    return NULL;}

  struct Image * Image2 = NULL;
  
  Image2 = malloc(sizeof(struct Image));
  Image2 -> width = w;
  Image2 -> height = h;
  Image2 -> comment = comment;
  Image2 -> data = malloc(sizeof(uint8_t) * w * h);
  
  Image_save(* fptr, * Image2);
  Image_free(* Image2);
  free(memory);
  free(comment);
  fclose(fptr);
  return Image2;
}

int Image_save(const char * filename, Image * image);

void Image_free(Image * image);

void linearNormalization(int width, int height, uint8_t * intensity)
{
  int ct; //Counter
  int max = 0;
  int min = 255;
  for(ct = 0; ct < width * height; ct++)
    {
      if(intensity[ct] > max){
	max = intensity[ct]; }
      if(intensity[ct] < min){
	min = intensity[ct]; }
    }
  for(ct = 0; ct < width * height; ct++)
    {
      intensity[ct] = (intensity - min) * 255 / (max - min);
    }
}

