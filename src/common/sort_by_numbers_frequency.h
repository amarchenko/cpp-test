#include <iostream>
#include <array>
#include <algorithm>
#include <map>
#include <vector>

// Given an unsorted array of natural numbers. Where numbers repeat in array.
// Out put numbers in the order of frequency. Where number of out put is
// passed as parameter.
// For Ex:
// Array -> [0, 0, 100, 3, 5, 4, 6, 4, 2, 100, 2, 100]
// n -> 2
// Out put -> [100, 0] or [100, 2]
// Since 100 is repeated 3 times and 0, 2 is repeated 2 times, output up to
// 2 most frequent elements, program should out put either 100, 0 or 100, 2

namespace sort_by_numbers_frequency {

using pair_ints = std::pair<int, int>;
using array_int = std::array<int, 12>;

bool PairCompareDesc(const std::pair<int, int>& a, const std::pair<int, int>& b) {
  return a.second != b.second ? a.second > b.second : a.first > b.first;
}

void PrintFreqNumbers(int quantity, array_int& input) {
  std::map<int, int> freq;

  for (auto& a: input) {
    ++freq[a];
  }

  std::vector<std::pair<int, int>> sorted_freq(freq.begin(), freq.end());
  std::sort(sorted_freq.begin(), sorted_freq.end(), PairCompareDesc);
    
  for (int i = 0; i < quantity; ++i) {
    std::cout << "[" << sorted_freq[i].first << ", " << sorted_freq[i].second
              << "]" << std::endl;
  }

}

int test()
{

  array_int input = {0, 0, 100, 3, 5, 4, 6, 4, 2, 100, 2, 100};
  int most_freq = 2;

  std::cout << "Numbers sequence: " << std::endl;
  for(auto& i: input) std::cout << i << " ";
  std::cout << std::endl;

  std::cout << most_freq << " most frequent: " << std::endl;
  PrintFreqNumbers(most_freq, input);

  return 1;
}

}

