#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int total = m + n;
        int leftSize = (total + 1) / 2;

        int low = 0;
        int high = m;

        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = leftSize - i;

            int nums1Left = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1Right = (i == m) ? INT_MAX : nums1[i];

            int nums2Left = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2Right = (j == n) ? INT_MAX : nums2[j];

            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
                if (total % 2 == 1) {
                    return max(nums1Left, nums2Left);
                } else {
                    return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0;
                }
            } else if (nums1Left > nums2Right) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }

        return 0.0;
    }
};

int main() {
    Solution sol;

    int m, n;
    cin >> m >> n;

    vector<int> nums1(m);
    vector<int> nums2(n);

    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    double ans = sol.findMedianSortedArrays(nums1, nums2);

    cout << "Median = " << ans << endl;

    return 0;
}