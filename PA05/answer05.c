#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

#include "answer05.h"

Image * Image_loadbmp(constant char * filename);

int Image_savebmp(const char * filename, Image * image);

Image * Image_load(const char * filename);

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

