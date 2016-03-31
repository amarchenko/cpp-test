#include <iostream>
#include <vector>

using namespace std;

// The game involves 2 players. The function below returns result for the first
// player, which starts first.
int findNimWinner(int num) {
  if (num <= 0) 
    return 0;
  else if (num == 1)
    return 1;

  return findNimWinner(num - 1) ^ findNimWinner(num - 2);
}

int findNimWinnerCached(int num, vector<int>& cache) {
  if (cache[num]) return cache[num];
  if (num <= 0) 
    return 0;
  else if (num == 1)
    return 1;

  cache[num - 1] = findNimWinnerCached(num - 1, cache);
  cache[num - 2] = findNimWinnerCached(num - 2, cache);

  return cache[num - 1] ^ cache[num - 2];
}

int main() {
  int i;
  cout << "Enter num of sticks: ";
  cin >> i;
  cout << "No cache: " << findNimWinner(i) << endl;

  vector<int> cache = {0, 1, 1, 0};
  cache.resize(i);
  cout << "With Cache: " << findNimWinnerCached(i, cache) << endl;

  for (int i = 0; i < cache.size(); ++i) {
    cout << "cache: " << i << " " << cache[i] << endl;
  }

  return 0;
}