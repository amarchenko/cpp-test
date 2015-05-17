#ifndef IS_POWER_OF_TWO_H_
#define IS_POWER_OF_TWO_H_

#include <iostream>

namespace is_power_of_two {

bool IsPowerOfTwo(int n) {
  return (n & (n - 1)) == 0;
}

int test() {
  int i = 8;
  int j = 5;
  std::cout << "Is " << i << " a power of 2? -> " << IsPowerOfTwo(i) << std::endl;
  std::cout << "Is " << j << " a power of 2? -> " << IsPowerOfTwo(j) << std::endl;
  return 1;
}

}

#endif // IS_POWER_OF_TWO_H_
