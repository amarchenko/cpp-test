//  tests6.h
//  author: andrey.krutogolov@gmail.com
//  date:   15.03.2013
// yandex

//Перепишите код, устранив имеющиеся в нём проблемы, но не изменяя функцию main
//
//class Foo {
// public:
//  Foo(int j) { i = new int[j]; }
//  ~Foo() { delete i; }
//
// private:
//  int* i;
//};
//
//class Bar: Foo {
// public:
//  Bar(int j) { i = new char[j]; }
//  ~Bar() { delete i; }
//
// private:
//  char* i;
//};
//
//void main() {
//  Foo* f = new Foo(100);
//  Foo* b = new Bar(200);
//  *f = *b;
//  delete f;
//  delete b;
//}

#ifndef TESTS6_H_
#define TESTS6_H_

#include <iostream>
using namespace std;

namespace tests6 {

class Foo {
 public:
  Foo(int j)
      : i_size(j) {
    cout << "Foo()\n";
    i = new int[j];
  }
  virtual ~Foo() {
    cout << "~Foo()\n";
    delete[] i;
  }

  Foo& operator=(const Foo& foo) {
    cout << "Foo::operator=()\n";
    // deep copy
    if (foo.i != NULL) {
      this->~Foo();
      i_size = foo.GetSize();
      i = new int[i_size];
      for (size_t s = 0; s < i_size; ++s) {
        i[s] = foo.i[s];
      }
    }
    return *this;
  }

  size_t GetSize() const {
    return i_size;
  }

 private:
  int* i;
  size_t i_size;
};

class Bar : public Foo {
 public:
  Bar(int j)
      : Foo(j) {
    cout << "Bar()\n";
    c = new char[j];
  }

  Bar& operator=(Bar& b) {
    cout << "Bar::operator=()\n";
    return *this;
  }

  virtual ~Bar() {
    cout << "~Bar()\n";
    if (c) {
      delete[] c;
    }
    c = 0;
  }

 private:
  char* c;
};

int main() {
  Foo* f = new Foo(100);
  Foo* b = new Bar(200);
  *f = *b;
  cout << "delete f:\n";
  delete f;
  cout << "delete b:\n";
  delete b;
  return 0;
}

}  // namespace tests6

#endif  // TESTS6_H_
