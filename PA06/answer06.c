#include <stdlib.h>
#include <stdio.h>

#include "answer06.h"
int main(void)
{
  partitionAll(4);
  return 0;
}
void partitionAll(int value) {
  int * buffer;
  int ind;
  int rec;

  //Base Set
  if(value == 0) {
    return;}
  //Initialize buffer
  buffer = malloc(sizeof(int) * value);
  
  //Partition Call
  for(rec = 1; rec <= value; rec ++) {
    buffer[value] = rec;
    partitionAll(value - rec); }

  //printing
  for(ind = 0; ind < value; ind++) {
      printf("%d + ", buffer[ind]);}
  printf("%d\n", buffer[value]);

  free(buffer);
  return;  
}

//void partitionIncreaing(int value);

//void partitionDecreasing(int value);

void partitionOdd(int value) {
  int * buffer;
  int ind;
  int rec;
  //Base Case
  if(value <= 0) {
    return; }
 
  for(rec = 1; rec <= value; rec += 2) {
    buffer[value] = rec;
    partitionOdd(value - rec); }

  for(ind = 0; ind < value; ind++) {
    printf("%d + ", buffer[ind]);}
  printf("%d \n", buffer[value]);

  free(buffer);
  return;
}

//void partitionEven(int value);

//void partitionOddAndEven(int value);

//void partitionPrime(int value);
