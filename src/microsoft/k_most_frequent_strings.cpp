#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class FrequentStrings {
public:
  FrequentStrings() {}

void Insert(const string& s);
void GetMostFreq(int n);

private:
  int m_max_freq;
  unordered_map<string, int> m_freq;
  map<int, vector<string> > m_strs;
};

void FrequentStrings::Insert(const string& s) {
  // remove new string from prev free group
  auto fit = m_freq.find(s);
  if (fit != m_freq.end()) {
    auto it = m_strs.find(fit->second);
    if (it != m_strs.end()) {
      for (auto vit = it->second.begin(); vit != it->second.end(); ++vit) {
        if (*vit == s) {
          it->second.erase(vit);
          break;
        }
      }
    }
  }
  // count frequency
  ++m_freq[s];
  // add new string to new freq group
  m_strs[m_freq[s]].push_back(s);
}

void FrequentStrings::GetMostFreq(int n) {
  cout << n << " most frequent strings" << endl;
  for (auto i = m_strs.rbegin(); i != m_strs.rend() && n > 0; ++i) {
    cout << "frequency " << i->first << ":";
    for (auto& j : i->second) {
      if (!n) break;
      cout << " " << j;
      --n;
    }
    cout << endl;
  }
}

int main() {
  FrequentStrings fs;
  fs.Insert("aaa");
  fs.Insert("bbb");
  fs.Insert("xxx");
  fs.Insert("rrr");
  fs.Insert("aaa");
  fs.Insert("aaa");
  fs.Insert("ccc");
  fs.Insert("ccc");
  fs.Insert("mmm");
  fs.Insert("bbb");
  fs.Insert("bbb");
  
  fs.GetMostFreq(3);
  return 0;
}