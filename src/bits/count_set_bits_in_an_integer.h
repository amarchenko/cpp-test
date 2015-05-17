/*
 * count_set_bits_in_an_integer.h
 *
 *  Created on: 02 ôåâð. 2015 ã.
 *      Author: andy
 */

#ifndef COUNT_SET_BITS_IN_AN_INTEGER_H_
#define COUNT_SET_BITS_IN_AN_INTEGER_H_

#include<stdio.h>

namespace count_set_bits_in_an_integer {

int countSetBits(unsigned int n) {
  unsigned int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

// Brian Kernighan’s Algorithm:

/* Function to get no of set bits in binary
 representation of passed binary no. */
int countSetBits2(int n) {
  unsigned int count = 0;
  while (n) {
    n &= (n - 1);
    count++;
  }
  return count;
}

/* Program to test function countSetBits */
int test() {
  unsigned int i = 4096;
  printf("Count set bit in %u - %d\n", i, countSetBits2(i));
  return 1;
}

/* Program to test function countSetBits */
int main() {
  int i = 9;
  printf("%d", countSetBits2(i));
  getchar();
  return 0;
}

}  // count_set_bits_in_an_integer

#endif /* COUNT_SET_BITS_IN_AN_INTEGER_H_ */
