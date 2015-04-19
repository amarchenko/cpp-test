/*
 * permutation_of_strings_characters.h
 *
 *  Created on: 19 Apr 2015
 *      Author: alex
 */

#ifndef PERMUTATION_OF_STRINGS_CHARACTERS_H_
#define PERMUTATION_OF_STRINGS_CHARACTERS_H_

namespace permutation_of_strings_charcters {
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Function to print permutations of strings characters
This function takes three parameters:
1. Array of words (as vector, for convenience)
2. Starting index of the array
3. Permutation. */
void permute(const vector<string> &words, int i, string permutation) {
    if (i == words.size()) {
        std::cout << permutation << std::endl;
    }
    else {
        std::string w = words[i];
        for (int j = 0; j < w.size(); ++j) {
            string new_permut = permutation + w[j];
            permute(words, i + 1, new_permut);
        }
    }
}


/* Driver program to test above functions */
int test() {
    vector<string> words = { "red", "fox", "super" };
    permute(words, 0, "");
    getchar();
    return 1;
}
}  // permutation_of_strings_characters

#endif /* PERMUTATION_OF_STRINGS_CHARACTERS_H_ */
