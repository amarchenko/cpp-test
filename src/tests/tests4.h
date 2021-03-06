#ifndef TESTS4_H_
#define TESTS4_H_

#include <iostream>

namespace tests4 {

class A {
 public:
  virtual ~A() {
  }
  void hello() {
    std::cout << "hello()" << std::endl;
  }
  virtual void hello1() {
    std::cout << "hello1()" << std::endl;
  }
};
// ...

int test() {

  A* a;
//  a->hello();

#pragma GCC diagnostic ignored "-Wuninitialized"
 a->hello1();

  return 1;
}

}

#endif  // TESTS4_H_
