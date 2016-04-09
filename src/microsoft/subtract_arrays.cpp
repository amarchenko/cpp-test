// Write function to calculate a difference A-B
// A={-89, 3, 4, 2, 7} B={-8, 1, 0, 2}
// Store result at A. No additional space allowed.

// A={-8, 2, 3, 4, 7, 8, 10} 
// B={-8, 0, 1, 2, 8}
// RESULT = {3, 4, 7, 8, 10}

// A-B={3, 4, 7, 10}

#include <iostream>
#include <vector>
using namespace std;

void SubtractArrays(vector<int>& a, vector<int>& b) {
  if (a.empty() || b.empty()) return;

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  
  int i = 0, j = 0;
  int open_ind = 0;
  while (i < a.size() || j < b.size()) {
    if (a[i] == b[j]) {
      ++i;
      ++j;
    } else if (a[i] > b[j]) {
      ++j;
    } else {
      a[open_ind++] = a[i++];
    }
  }

  // delete remaining elements
  while(open_ind < a.size()) {
    a.erase(a.begin() + open_ind++);
  }
}


int main() {
  vector<int> a = {8, 7, 3, 4, 10};
  vector<int> b = {0, 8, 2, 1};

  SubtractArrays(a, b);

  for (auto& i : a) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
