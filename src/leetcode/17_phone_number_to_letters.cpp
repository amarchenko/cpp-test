#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    int length = digits.size();
    if (!length) return vector<string>();

    int current = 0;
    string permut;
    permut.resize(length);

    permutations(digits, length, current, permut);
    return result;

  }
private:
    void permutations(string& digits, int& length, int current,
                    string permut) {

    if (current == length) {
      result.push_back(permut);
      return;
    };

    auto it = table.find(digits[current]);
    string letters;
    if (it == table.end()) {
      cout << "can't find digit" << digits[current] << " in the mapping table"
          << endl;
      return;
    } else {
      letters = it->second;
    }

    for (int i = 0; i < letters.size(); ++i) {
      if (letters[i]) {
        permut[current] = letters[i];
        permutations(digits, length, current + 1, permut);
      }
    }
  }

  vector<string> result;
  map<char, string> table =
      {{'0', " "}, {'1', ""}, {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
      {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
};

int main() {
  Solution s;
  auto vec = s.letterCombinations("23");
  for (auto v : vec) {
    cout << "v: " << v << endl;
  }
  return 0;
}