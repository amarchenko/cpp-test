// Given a ladder with N stairs. You may step over 1, 2 and 3 stairs.
// How many unique combinations exists to go up the ladder?
// Input: N = 3
// Output: 4
// [1,1,1], [1,2], [2,1], [3]

#include <iostream>

using namespace std;

int ladderCombos(int num) {
  if (num == 0) return 1;
  else if (num < 0) return 0;

  return ladderCombos(num - 1) +
         ladderCombos(num - 2) +
         ladderCombos(num - 3);
}

int main() {
  int i;
  cout << "Enter num of ladders: ";
  cin >> i;
  cout << "Num of combinations: " << ladderCombos(i) << endl;
}