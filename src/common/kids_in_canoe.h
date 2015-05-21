#ifndef define KIDS_IN_CANOE_H_
#define KIDS_IN_CANOE_H_

#include <iostream>
#include <vector>
#include <algorithm>

/*
 * If a canoe can hold 2 kids and a max weight of 150 lbs,
 * write a function that returns the minimum number of canoes needed,
 * given a list of kids and their weights.
 *
 * Created on May 21, 2015
 * By Alex
 */

namespace kids_in_canoe {

static const int kMaxCanoeWeight = 150

// input array will be modified
int MinCanoes(std::vector<int>& weights) {
  if (weights.empty()) return 0;

  // use STL sort, O(n*logn)
  std::sort(weights.begin(), weights.end());

  int low_index = 0, count = 0;
  int high_index = weights.size() - 1;

  while (low_index < high_index) {
    if (weights[low_index] + weights[high_index] <= kMaxCanoeWeight) {
      ++low_index;
      --high_index;
      ++count;
    } else if (weights[high_index] <= kMaxCanoeWeight) {
      --high_index;
      ++count;

    }
  }
  if (low_index == high_index && weights[high_index] <= kMaxCanoeWeight) {
    ++count;
  }
  return count;
}

}

#endif // KIDS_IN_CANOE_H_
