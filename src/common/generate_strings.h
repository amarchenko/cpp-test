#ifndef GENERATE_STRINGS_
#define GENERATE_STRINGS_

#include <iostream>
#include <string>

/*
* Given a string (for example: "a?bc?def?g"),
* write a program to generate all the possible strings
* by replacing ? (question mark) with 0 (zeros) and 1 (oness).
* Example:
* Input : a?b?c?
* Output: a0b0c0, a0b0c1, a0b1c0, a0b1c1, a1b0c0, a1b0c1, a1b1c0, a1b1c1.
*
* Created on May 4, 2015
* By Alex
*/

namespace generate_strings {

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

int test() {
    std::string test = "abc?def?gh?";
    ReplaceByZerosOnes(test);
    return 1;
}

}

#endif /* GENERATE_STRINGS_ */
