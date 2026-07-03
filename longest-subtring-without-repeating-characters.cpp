#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            while (seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }

            seen.insert(s[right]);
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s;
    getline(cin, s);

    cout << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}