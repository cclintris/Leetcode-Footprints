#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: piles = [3,6,7,11], h = 8
 * O: 4
 *
 * I: piles = [30,11,23,4,20], h = 5
 * O: 30
 *
 * I: piles = [30,11,23,4,20], h = 6
 * O: 23
 */

int minEatingSpeed(vector<int>& piles, int h);

int main(int argc, char const* argv[]) {
    return 0;
}

// Brute force: TLE
int minEatingSpeed(vector<int>& piles, int h) {
    int speed = 1;
    while (1) {
        int hourSpent = 0;
        for (auto pile : piles) {
            hourSpent += (pile / speed) + (pile % speed != 0);
            if (hourSpent > h)
                break;
        }

        if (hourSpent <= h) {
            return speed;
        } else {
            speed++;
        }
    }
}

// Optimal: Binary search
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end());
    while (low < high) {
        int speed = (low + high) / 2;
        int hourSpent = 0;
        for (auto pile : piles) {
            hourSpent += (pile / speed) + (pile % speed != 0);
        }

        if (hourSpent > h) {
            low = speed + 1;
        } else {
            high = speed;
        }
    }
    return high;
}
