#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findMaxSumNoncont(vector<int>& input) {
    if(!input.size()) return 0;

    int sum = input[0];
    for (int i = 1; i < input.size(); ++i) {
        if (sum + input[i] > sum) sum += input[i];
        else if (input[i] > sum) sum = input[i];
    }
    return sum;
}

int findMaxSumCont(vector<int>& input) {
    if(!input.size()) return 0;

    int max_sum = input[0];
    int sum = input[0];
    for (int i = 1; i < input.size(); ++i) {
        //sum = std::max(std::max(sum, sum + input[i]), std::max(sum, input[i]));
        sum = std::max(input[i], sum + input[i]);
        max_sum = std::max(max_sum, sum);
    }
    return max_sum;
}


int main() {
    vector<int> input = {-100, -1};
    cout << findMaxSumCont(input) << " ";
    cout << findMaxSumNoncont(input) << endl;

    return 0;
}
