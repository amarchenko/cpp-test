#include <iostream>
#include <vector>
using namespace std;

/* class Stats
     insert()
     getMean()
     getMedian()
     
  1) O(1) memory
  2) [0, 1000)
  3) [2, 7, 3, 9, 4] -> mean 5, median 4
  */

// lost you, let me call you back
const int STATS_SIZE = 1000;

class Stats {
public:
Stats() {
  numbers.resize(STATS_SIZE);
}

void insert(int i) {
  ++numbers[i];
  ++size;
}
  
float getMean() {
  float sum = 0;
  int n = 0;
  for (unsigned int i = 0; i < numbers.size(); ++i) {
    sum += i * numbers[i];
    n += numbers[i];
  }
  sum /= n;
  return sum;
}
  
float getMedian() {
  if (size % 2 == 0) {
    cout << "Even" << endl;
    int mid1 = size / 2;
    int mid2 = mid1 - 1;
    int i =0;
    int j = 0;
    for(i = 0; mid1 <= 0; ++i) {
      mid1 -= numbers[i];
    }
    for(j = 0; mid2 <= 0; ++j) {
      mid2 -= numbers[j];
    }
    return (numbers[i] + numbers[j]) / 2;
  } else {
    cout << "Odd" << endl;
    int mid = size / 2;
    cout << "Mid: " << mid << endl;
    int i;
    for(i = 0; mid > 0; ++i) {
      cout << "i:" << i << endl;
      mid -= numbers[i];
    }
    return i;
  }
}
  
private:
  vector<int> numbers;
  int size = 0;
};

// To execute C++, please define "int main()"
int main() {
  Stats st;
  st.insert(1);
  st.insert(4);
  st.insert(5);
  cout << "Mean: " << st.getMean() << endl;
  cout << "Median: " << st.getMedian() << endl;
  return 0;
}
