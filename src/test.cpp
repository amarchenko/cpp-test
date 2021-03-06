#include "test.h"

#include <stdio.h>
#include <iostream>
#include <assert.h>

#include "bits/count_set_bits_in_an_integer.h"
#include "bits/is_power_of_two.h"

#include "common/bst.h"
#include "common/binary_tree.h"
#include "common/linked_list.h"
#include "common/longest_common_subsequence.h"
#include "common/circular_que.h"
#include "common/generate_strings.h"
#include "common/node.h"
#include "common/sort_by_numbers_frequency.h"

#include "algoritms/algoritms.h"
#include "array/array.h"
#include "clock/clock.h"
#include "cpp0x/cpp0x.h"
#include "cci4/cracking4.h"
#include "cci5/cracking5.h"
#include "exception/exceptions.h"
#include "facebook/facebook.h"
#include "func/func.h"
#include "hashcode/hashcodes.h"
#include "language/language.h"
#include "lambda/lambda.h"
#include "lock-free/lock_free.h"
#include "memory/mem_test.h"
#include "patterns/patterns.h"
#include "templates/templates.h"
#include "smart_ptr/smart_ptr.h"
#include "sqrt/sqrt.h"
#include "static/static.h"
#include "stl/stl.h"
#include "tests/tests.h"
#include "quiz/quiz.h"
#include "virtual/virtuals.h"

#include "overloading/overloading.h"
#include "moto/moto.h"

#include "logger/logger.h"

#include "last/last_1.h"
#include "epam/epam.h"
#include "epam/google2.h"

#include "ms/ms.h"
#include "memory/alignment.h"

#include "cpp11/quick_sort.h"

int main(int argc, char **argv) {
  logger::LogMethodWrapper l("All test cases");

// assert(algorithms::test());
// assert(binary_tree::test());
// assert(bst::test());
// assert(cpp0x::test());
// assert(cracking::test());
// assert(cracking5::test());
// assert(exceptions::test());
// assert(facebook::test());
// assert(func::test());
// assert(hashcodes::test());
// assert(lambda::test());
// assert(language::test());

// assert(sqrt_::test());
// assert(mem_test::test());
// assert(moto::test());
// assert(templates::test());

// assert(overloading::test());

// assert(patterns::test());
// assert(quiz::test());
// assert(smart_ptr::test());
// assert(stl::test());
// assert(binary_tree::test());
// assert(tests::test());
// assert(virtuals::test());

// assert(last_1::test());
// assert(static_::test());

// assert(array::test());
// assert(clock_::test());

// assert(quicksort_cpp11::test());

// assert(epam::test() );
// assert(ms::test() );

// assert(alignment::test());
// assert(permutation_of_strings_charcters::test());
// assert(generate_strings::test());

// assert(longest_common_subsequence::test());

// assert(count_set_bits_in_an_integer::test());
// assert(is_power_of_two::test());
// assert(reverse_char_array::test());

  assert(sort_by_numbers_frequency::test());

  int arr[10];
  int *pa = arr;

  return 0;

}

