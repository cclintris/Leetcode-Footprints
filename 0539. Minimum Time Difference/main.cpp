#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * I: timePoints = ["23:59","00:00"]
 * O: 1
 *
 * I: timePoints = ["00:00","23:59","00:00"]
 * O: 0
 */

int findMinDifference(vector<string>& timePoints);

int main(int argc, char const* argv[]) {
    return 0;
}

int findMinDifference(vector<string>& timePoints) {
    int res = INT_MAX, pre = 0, first = INT_MAX, last = INT_MIN;
    vector<int> mask(1440, 0);
    for (string str : timePoints) {
        int h = stoi(str.substr(0, 2)), m = stoi(str.substr(3));
        if (mask[h * 60 + m] == 1) return 0;
        mask[h * 60 + m] = 1;
    }
    for (int i = 0; i < 1440; ++i) {
        if (mask[i] == 1) {
            if (first != INT_MAX) {
                res = min(res, i - pre);
            }
            first = min(first, i);
            last = max(last, i);
            pre = i;
        }
    }
    return min(res, 1440 + first - last);
}
