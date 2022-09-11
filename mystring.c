#include <stdlib.h>
#include "mystring.h"

//return the string length by iterating until '\0'(end of string)
int mystrlen(char * s) {
  int len = 0;
  char *ptr = s;
  while(*ptr != '\0') {
    len++;
    ptr++;
  }
  return len;
}

//return the target location and copy another string's content
// by iterating until '\0'(end of string)
char * mystrcpy(char * dest, char * src) {
  char * destInitial = dest;
  while(*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
  return destInitial ;
}

char * mystrcat(char * dest, char * src) {
  char * destinitial = dest;
  while(*dest != '\0') {
    dest++;
  }
//after dest reach string's end, do the similar process like strcpy,
//return the intial position
  while(*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
  return destinitial ;
}

//compare the value of same index each time,
// return -1 for s1 < s2, 1 for s1>s2, 0 for eqaulity.
int mystrcmp(char * s1, char * s2) {
  int cmpResult = 0;
  while(*s1 && *s1 == *s2) {
    s1++;
    s2++;
  }
  cmpResult  = *s1 - *s2;
  if(cmpResult  <0) {
    return -1;
  } else if(cmpResult  > 0) {
    return 1;
  }
  return 0;
}


char * mystrstr(char * hay, char * needle) {
  char* ptr = hay;
  char* ptr1 = needle;
  //iteration with method like Brute-force to find substring
  while(*ptr != '\0') {
    int count = 0;
    while(*ptr1 && *ptr1 == *ptr) {
      count++;
      ptr++;
      ptr1++;
    }
    //return the postion where find substring needle
    if (*ptr1 == '\0') {
      return ptr - count;
    }
    //reset both pointers to the start
    ptr -= count;
    ptr1 -= count;
    ptr++;
  }
  return NULL;
}

char * mystrdup(char * s) {
  char *str;
  char *ptr;
  int len = 0;
  while (*s != '\0') {
    s++;
    len++;
  }
  s -= len;
//get the length of s and reset s to start
  str = malloc(len + 1);
  ptr = str;
  while (*s) {
    *ptr++ = *s++;
  }
    *ptr = '\0';
    return str;
//copy the each element in c to new allocated memory
}

//cope n elements of the string to anthoer location
char * mymemcpy(char * dest, char * src, int n) {
  if((dest != NULL) && (src != NULL)) {
    while(n) {
      *dest++ = *src++;
      n--;
    }
  }
  return dest;
}


