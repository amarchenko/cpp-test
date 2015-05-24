/*
* Created on May 4, 2015
* By Alex
*/

#ifndef GENERATE_STRINGS_
#define GENERATE_STRINGS_

#include <iostream>
#include <string>

namespace generate_strings {

/*
* Given a string (for example: "a?bc?def?g"),
* write a program to generate all the possible strings
* by replacing ? (question mark) with 0 (zeros) and 1 (oness).
* Example:
* Input : a?b?c?
* Output: a0b0c0, a0b0c1, a0b1c0, a0b1c1, a1b0c0, a1b0c1, a1b1c0, a1b1c1.
*/

void ReplaceByZerosOnes(const std::string& str, unsigned int pos) {

    if (pos == str.size()) {
        std::cout << str << std::endl;
        return;
    }

    if (str[pos] == '?') {
        std::string prefix = str.substr(0, pos);
        std::string suffix = str.substr(pos + 1);
        ReplaceByZerosOnes(prefix + '0' + suffix, pos + 1);
        ReplaceByZerosOnes(prefix + '1' + suffix, pos + 1);
    } else {
        ReplaceByZerosOnes(str, pos + 1);
    }
}

/* Default arguments are prohibited by Google code-style */
void ReplaceByZerosOnes(const std::string& str) {
    ReplaceByZerosOnes(str, 0);
}

/*
* i18n (where 18 stands for the number of letters between the first i and
* the last n in the word “internationalization”).
* Generate all such possible i18n strings for any given string.
* Example:
* Input: "careercup"
* Output: "c7p","ca6p","c6up","car5p","ca5up","care4p","car4up","caree3p",
* "care3up" ... till the count is 0 which means its the complete string again.
*/

void GenerateI18NStrings(const std::string& input) {
    int n = input.size();

    for (int i = n - 2; i >= 1; --i) { // mind first and last characters
        for (int j = 1; j <= n- i -1; ++j ) {
            std::cout << input.substr(0, j) << i << input.substr(i + j) <<
                std::endl;
        }
    }

}

int test() {
    std::string zero_one_test = "abc?def?gh?";
    std::cout << "Replace ? by 0 & 1 in string: " << test << std::endl;
    ReplaceByZerosOnes(zero_one_test);

    std::string i18n_test = "careercup";
    std::cout << "Generate i18n strings for: " << i18n_test << std::endl;
    GenerateI18NStrings(i18n_test);

    return 1;
}

}

#endif /* GENERATE_STRINGS_ */
