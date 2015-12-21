// Given nums = [-2, 0, 3, -5, 2, -1]

// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

#include <iostream>
#include <vector>
#include <numeric>

using std::cout;
using std::endl;
using std::vector;

class NumArray {
public:
  NumArray(vector<int> &nums) : psum_(nums.size() + 1, 0) {
    partial_sum(nums.begin(), nums.end(), psum_.begin() + 1);
  }

  int sumRange(int i, int j) {
    return psum_[j+1] - psum_[i];
  }
private:
  vector<int> psum_;
};

int main() {
  vector<int> nums = {-2, 0, 3, -5, 2, -1};

  NumArray na(nums);

  cout << na.sumRange(0, 2) << endl;
  cout << na.sumRange(2, 5) << endl;
  cout << na.sumRange(0, 5) << endl;

  return 0;
}

