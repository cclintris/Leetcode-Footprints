#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: ribbons = [9,7,5], k = 3
 * O: 5
 *
 * I: ribbons = [7,5,9], k = 4
 * O:  4
 *
 * I: ribbons = [5,7,9], k = 22
 * O: 0
 */

int maxLength(vector<int>& ribbons, int k);

bool canCut(vector<int>& ribbons, int len, int k);

int main(int argc, char const* argv[]) {
    return 0;
}

// Binary search
int maxLength(vector<int>& ribbons, int k) {
    int max = -1;
    for (int i = 0; i < ribbons.size(); i++) {
        if (ribbons[i] > max) max = ribbons[i];
    }
    int low = 1, high = max;
    int res = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canCut(ribbons, mid, k)) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

bool canCut(vector<int>& ribbons, int len, int k) {
    int cuts = 0;
    for (int i = 0; i < ribbons.size(); i++) {
        cuts += (ribbons[i] / len);
    }
    return cuts >= k;
}
