#include <iostream>
#include <vector>
using namespace std;

/**
 * I:
 * O:
 *
 * I:
 * O:
 *
 * I:
 * O:
 */

int numPairsDivisibleBy60(vector<int>& time);

int main(int argc, char const* argv[]) {
    return 0;
}

int numPairsDivisibleBy60(vector<int>& time) {
    vector<int> arr(60, 0);
    int cnt = 0;
    for (auto t : time) {
        if (t % 60 == 0) {
            cnt += arr[0];
        } else {
            cnt += arr[60 - t % 60];
        }
        arr[t % 60]++;
    }
    return cnt;
}
