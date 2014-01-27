#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
  int ct;
  int sum = 0;
  for(ct = 0; ct < len; ct++)
    {
      array[ct] += sum;
    }

  return sum;
}

int arrayCountNegative(int * array, int len)
{
  int neg;
  int ct;
  for(ct = 0; ct < len; ct++)
    {
      if(array[ct] < 0)
	{
	  neg++;
	}
    }
    return neg;
}

int arrayIsIncreasing(int * array, int len)
{    
  int ct = 0;
  int xxx = 1;
  int zzz;
  if(len == 0)
    {
      return xxx;
    }
  zzz = array[0];
  for(ct = 0; ct < len; ct++)
    {
      if(zzz < array[ct])
	{
	  xxx = 1;
	  zzz = array[ct];
	}
      if(array[ct] < zzz)
	{
	  xxx = 0;
	  return xxx;
	}
    }
  return xxx;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
  int finder = -1;
  int ct;
  for(ct=0; ct < len; ct++)
    {
      if(haystack[ct] == needle)
	{
	  finder = ct;
	}
    }
    return finder;
}

int arrayFindSmallest(int * array, int len)
{
  int ct;
  int finder = 0;
  int min = 0;
  
  if(len == 0)
    {
      return 0;
    }
  min = array[finder];

  for(ct = 0; ct < len; ct++)
    {
      if(array[ct] < min)
	{
	  min = array[ct];
	  finder = ct;
	}
    }
  return finder;
}
