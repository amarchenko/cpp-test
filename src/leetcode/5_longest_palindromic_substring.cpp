// Find the longest palindromic substring

#include <iostream>
using namespace std;

bool isPalindrome(const string& str) {
  if (str.empty()) return false;

  int n = str.size();
  for (int i = 0; i < n / 2; ++i) {
    if (str[i] != str[n - 1 - i]) return false;
  }
  return true;
}

string getPalindrome(const string& str, int b, int e) {
  if (b == 0 && e == 0) {
    return str.substr(0, 1);
  }
  while(0 < b && e <= str.size() - 1 && str[b] == str[e] ) {
    --b;
    ++e;
  }
  return str.substr(b + 1, e - b - 1);
}

string longestPolindrome(string& str) {
  if (str.empty() || str.size() == 1) return str;

  string longest = str.substr(0, 1);
  for (int i = 0; i < str.size() - 1; ++i) {
    auto poli = getPalindrome(str, i, i);
    if (poli.size() > longest.size()) {
      longest = poli;
    }
    poli = getPalindrome(str, i, i + 1);
    if (poli.size() > longest.size()) {
      longest = poli;
    }
  }
  return longest;
}

int main() {
  // string input = "zbccba";
  string input = "abcggcnytfsdffdst";

  cout << "Longest Poli: " << longestPolindrome(input) << endl;
  
  return 0;
}