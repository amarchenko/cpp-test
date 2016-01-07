#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    {
        if (x == 0) {
            return 0;
        } else {
            int res = 0;
            int _x = abs(x);
            int flag = _x / x;
            while (_x > 0) {
                int curr = _x % 10;
                //in case overflow
                if (res > (INT_MAX - curr) / 10) {
                   return 0;
                } else  {
                    res  = res * 10 + curr;
                    _x = _x / 10;
                }
            }
            return flag * res;
        }
    }
};

int main() {
    Solution s;
    int input = -369;
    cout << "input: " << input << endl;
    cout << "result: " << s.reverse(input) << endl;
    return 0;
}
