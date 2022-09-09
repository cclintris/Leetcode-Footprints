#include <iostream>
#include <vector>
using namespace std;

/**
 * I: n = 19
 * O: true
 * Explanation:
    12 + 92 = 82
    82 + 22 = 68
    62 + 82 = 100
    12 + 02 + 02 = 1
 *
 * I: n = 2
 * O: false
 */

bool isHappy(int n);

int main(int argc, char const* argv[]) {
    int n = 2;
    cout << isHappy(n) << endl;
    return 0;
}

bool isHappy(int n) {
    vector<int> nums;
    nums.push_back(n);
    while (1) {
        // cout << "n: " << n << endl;
        int tmp = 0;
        while (n > 0) {
            int r = n % 10;
            tmp += r * r;
            n /= 10;
        }
        n = tmp;
        // cout << "n: " << n << endl;
        if (n == 1) return true;
        if (find(nums.begin(), nums.end(), n) != nums.end()) return false;
        nums.push_back(n);
    }
}
