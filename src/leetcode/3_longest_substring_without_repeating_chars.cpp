#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {
        positions = vector<int>(256, -1);
    }
    int lengthOfLongestSubstring(string str) {
        if (str.empty()) return 0;
        
        int start = 0, result = 0;
        int length = str.size();
        for (int i = 0; i < length; ++i) {
            if (positions[str[i]] >= start) {
                start = positions[str[i]] + 1;
            }
            result  = max(result, i - start + 1);
            positions[str[i]] = i;
        }

        return result;
    }
private:
    vector<int> positions;
};

int main() {
  Solution s;
  string test = "vabcvdf";
  auto res = s.lengthOfLongestSubstring(test);
  cout << test << ", result is " << res << endl;
  return 0;
}