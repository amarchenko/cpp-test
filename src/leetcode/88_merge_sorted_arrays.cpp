#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m <= 0) {
            nums1 = nums2;
            return;
        } else if (n <= 0) {
            return;
        }

        nums1.resize(m + n);

        int i = m - 1;
        int j = n - 1;
        for (int k = m + n - 1; k >= 0; --k) {
            if (i < 0) {
                nums1[k] = nums2[j--];
            } else if (j < 0) {
                nums1[k] = nums1[i--];
            } else if ((nums1[i] > nums2[j]) || j < 0) {
                nums1[k] = nums1[i--];
            } else {
                nums1[k] = nums2[j--];
            }
        }
    }
};

int main() {
    Solution s;

    vector<int> a1 = {0, 1, 2, 7, 9};
    vector<int> a2 = {2, 3, 6};

    s.merge(a1, a1.size(), a2, a2.size());

    for (auto a : a1) {
        cout << "a: " << a << endl;
    }

}