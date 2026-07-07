#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }

        vector<string> rows(numRows);

        int row = 0;
        int direction = 1;

        for (char c : s) {
            rows[row] += c;

            if (row == 0) {
                direction = 1;
            } else if (row == numRows - 1) {
                direction = -1;
            }

            row += direction;
        }

        string ans;
        for (string& r : rows) {
            ans += r;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s;
    int numRows;

    cout << "enter s: ";
    cin >> s;

    cout << "enter numRows: ";
    cin >> numRows;

    string result = sol.convert(s, numRows);

    cout << "result: " << result << endl;

    return 0;
}
