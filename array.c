#include <stdio.h>

#include "array.h"

// Return sum of first n elements of an array
double sumArray(int n, double * array) {
  double sum = 0;
  double * startPtr = array;
  double * endPtr = startPtr + n;
  while (startPtr < endPtr) {
    sum += *startPtr;
    startPtr++;
  }
  return sum;
}

// Return element with max value among n elements of an array
double maxArray(int n, double * array) {
  double max = 0;
  double * startPtr = array;
  double * endPtr = startPtr + n;
  while(startPtr < endPtr){
    max = max < *startPtr ? *startPtr : max;
    *startPtr++;
  }
  return max;
}

// Return element with min value among first n elements of an array

double minArray(int n, double * array) {
  double max = 0;
  double * startPtr = array;
  double * endPtr = startPtr + n;
  while(startPtr < endPtr){
    max = max > *startPtr ? *startPtr : max;
    *startPtr++;
  }
  return max;
}

// Find the position of first int which has value between min and max 
//  among first n elements of an array, or -1 if not found
int findArray(int n, double * array, double min, double max) {
  double * startPtr = array;
  double * endPtr = startPtr + n;
  int index = 0;
  while(startPtr  < endPtr ) {
    if (*startPtr <= max && *startPtr >= min) {
      return index;
    }
    index++;
    startPtr++;
  }
  return -1;
}

// Sort array without using [] operator. Use pointers 
// Hint: Use a pointer to the current and another to the next element
int sortArray(int n, double * array) {
  //I apply a slection sort in this function
  //find the lowest value in each iteration
  //and then iteration starts at next index
  int k = 0;
  double *ptr = array;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (*(ptr + j) < *(ptr + i)) {
        k = *(ptr + i);
        *(ptr + i) = *(ptr + j);
        *(ptr + j) = k;
      }
    }
  }
}

// Print each elements of an arrat
void printArray(int n, double * array) {
  int index = 0;
  double * startPtr = array;
  double * endPtr = startPtr + n;
  while (startPtr  < endPtr ) {
    printf("%d:%lf\n", index,*startPtr );
    index++;
    startPtr ++;
  }
}
