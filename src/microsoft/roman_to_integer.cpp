#include <iostream>
#include <map>
#include <string>
using namespace std;

// MeDiCaL XaVIer

std::map<char, int> roman_nums = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                  {'C', 100}, {'D', 500}, {'M', 1000}};

std::map<string, int> roman_exceptions = {{"IV", 4}, {"IX", 9}, {"XL", 40}, 
                                          {"XC", 90}, {"CD", 400}, {"CM", 900}};

int romanToInt(const string& input) {
if (!input.size()) return 0;
if (input.size() == 1) return roman_nums[input[0]];

int result = 0;

  for(int i = 0; i < input.size(); ++i) {
    auto cur = roman_nums.find(input[i]);
    auto next = roman_nums.find(input[i+1]);
    if (cur != roman_nums.end() && next != roman_nums.end() &&
        cur->second < next->second) {
      string key(1, input[i]);
      key += input[i+1];
      auto it = roman_exceptions.find(key);
       if (it != roman_exceptions.end()) {
        result += it->second;
        ++i;
      } 
    } else {
      auto it = roman_nums.find(input[i]);
      if (it != roman_nums.end()) {
        result += it->second;
      }
    }
  }
  return result;
}

int main() {
  cout << "Input Roman number -> ";
  string input;
  cin >> input;
  cout << romanToInt(input) << endl;
  return 0;
}