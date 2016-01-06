// Given an integer, convert it to a roman numeral.
// Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

map<int, string> roman_nums = {
  {0, ""},
  {1, "I"},
  {2, "II"},
  {3, "III"},
  {4, "IV"},
  {5, "V"},
  {6, "VI"},
  {7, "VII"},
  {8, "VIII"},
  {9, "IX"},
  {10, "X"},
  {20, "XX"},
  {30, "XXX"},
  {40, "XL"},
  {50, "L"},
  {60, "LX"},
  {70, "LXX"},
  {80, "LXXX"},
  {90, "XC"},
  {100, "C"},
  {200, "CC"},
  {300, "CCC"},
  {400, "CD"},
  {500, "D"},
  {600, "DC"},
  {700, "DCC"},
  {800, "DCCC"},
  {900, "CM"},
  {1000, "M"},
  {2000, "MM"},
  {3000, "MMM"},
  {4000, "MMMM"}
};

class Solution {
public:
string intToRoman(int num) {
  string result = "";
  int num_len = 1;
  for (auto i = num; i > 9; i /= 10, ++num_len);

  int order, d;
  for (auto l = num_len; l > 0; --l) {
    order = pow(10, l - 1);
    d = num / order;
    result += roman_nums[d * order];
    num -= d * order;
  }
  return result;
}

};

int main() {
  Solution s;
  int i = 123;
  cout << "input: " << i << endl;
  cout << "result: " << s.intToRoman(i) << endl;
  return 0;
}
