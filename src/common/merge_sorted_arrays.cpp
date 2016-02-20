// Merge k sorted arrays and return it as one array
#include <iostream>
#include <queue>

using namespace std;
using priority_queue_min = priority_queue<int, vector<int>, greater<int> >;

vector<int>* MergeSortedArrays(const vector< vector<int> >& arrays,  int& k) {
  if (k <= 0) return nullptr;

  priority_queue_min* heap = new priority_queue_min();

  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < arrays[i].size(); ++j) {
      heap->push(arrays[i][j]);
    }
  }

  vector<int>* result = new vector<int>();

  while(!heap->empty()) {
    result->push_back(heap->top());
    heap->pop();
  }

  return result;
}

int main() {
  int k = 3;
  vector< vector<int> > arrays(k, std::vector<int>(k));
  arrays[0] = {5, 6, 9};
  arrays[1] = {1, 4, 10, 11, 12};
  arrays[2] = {3, 23, 56};

  unique_ptr<vector<int>> res(MergeSortedArrays(arrays, k));

  cout << "Merged sorted arrays:";
  for (auto& r : *res) {
    cout << " " << r;
  }
  cout << endl;

  return 0;
}