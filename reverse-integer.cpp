#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reversed = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (reversed > INT_MAX / 10 ||
                (reversed == INT_MAX / 10 && digit > 7)) {
                return 0;
            }

            if (reversed < INT_MIN / 10 ||
                (reversed == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            reversed = reversed * 10 + digit;
        }

        return reversed;
    }
};

int main() {
    Solution solution;
    int x;

    cout << "Enter an integer: ";
    if (!(cin >> x)) {
        cout << "Invalid input\n";
        return 1;
    }

    cout << solution.reverse(x) << '\n';
    return 0;
}
