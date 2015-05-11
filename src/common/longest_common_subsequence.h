#ifndef LONGEST_COMMON_SUBSEQUESNCE_H_
#define LONGEST_COMMON_SUBSEQUESNCE_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <memory>

// Given a string(1 - d array), find if there is any sub - sequence that repeats itself.
// Here, sub - sequence can be a non - contiguous pattern, with the same relative order.

// Eg:
// 1. abab <------yes, ab is repeated
// 2. abba <----No, a and b follow different order
// 3. acbdaghfb <--------yes there is a followed by b at two places
// 4. abcdacb <---- - yes a followed by b twice
//
// The above should be applicable to ANY TWO(or every two) characters in the string and optimum over time.
//
// In the sense, it should be checked for every pair of characters in the string.

// Repeated subsequence in the same string

// TO DO

namespace longest_common_subsequence {

// Longest Common Subsequence, length only, iterative
int LCSLength(const std::string& strA, const std::string& strB) {
    const int m = strA.size();
    const int n = strB.size();

    // 2d dynamic array
    int** L = new int*[m + 1];
    for (int i = 0; i < m + 1; ++i) {
        L[i] = new int[n + 1];
    }

    for (int i = m; i >= 0; --i) {
        for (int j = n; j >= 0; --j) {
            if (!strA[i] || !strB[j]) L[i][j] = 0;
            else if (strA[i] == strB[j]) L[i][j] = 1 + L[i + 1][j + 1];
            else L[i][j] = std::max(L[i + 1][j], L[i][j + 1]);

            // std::cout << "L[" << i << "][" << j << "] = " << L[i][j] << std::endl;
        }
    }
    
    return L[0][0];
}

// Longest Common Subsequence, length only, recursive
int LCSLengthRecursive(const std::string& s1, const int& i, const std::string& s2, const int& j) {
    if (!s1[i] || !s2[j]) return 0;

    if (s1[i] == s2[j]) {
        return 1 + LCSLengthRecursive(s1, i + 1, s2, j + 1);
    } else {
        return std::max(LCSLengthRecursive(s1, i + 1, s2, j),
            LCSLengthRecursive(s1, i, s2, j + 1));
    }
}

int LCSLengthRecursive(const std::string& s1, const std::string& s2) {
    return LCSLengthRecursive(s1, 0, s2, 0);
}

int test() {
    std::string s1 = {"abcdddqwe"};
    std::string s2 = {"abcdabg"};

    std::cout << "String1: " << s1 << std::endl;
    std::cout << "String2: " << s2 << std::endl;
    std::cout << "LCS length recursive: " << LCSLengthRecursive(s1, s2) << std::endl;
    std::cout << "LCS length iterative: " << LCSLength(s1, s2) << std::endl;

    // std::cout << "String: " << s2 << std::endl;
    // std::cout << "Repeated sub length: " << RepeatedSubsequence(s2, 0, 1) << std::endl;

    return 1;
}

}

#endif // LONGEST_COMMON_SUBSEQUESNCE_H_