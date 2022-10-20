#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 * I: nums = [1,2,2]
 * O: 1
 * Explanation: After 1 move, the array could be [1, 2, 3]
 *
 * I: nums = [3,2,1,2,1,7]
 * O: 6
 * Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
    It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
 *
 * I:
 * O:
 */

int minIncrementForUnique(vector<int>& nums);

int main(int argc, char const* argv[]) {
    return 0;
}

int minIncrementForUnique(vector<int>& nums) {
    int res = 0;
    sort(nums.begin(), nums.end());
    int need = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (need > nums[i]) {
            res += (need - nums[i]);
        }
        need = max(need, nums[i]) + 1;
    }
    return res;
}

int minIncrementForUnique(vector<int>& A) {
    int res = 0, need = 0;
    map<int, int> numCnt;
    for (int num : A) ++numCnt[num];
    for (auto& a : numCnt) {
        res += a.second * max(need - a.first, 0) + a.second * (a.second - 1) / 2;
        need = max(need, a.first) + a.second;
    }
    return res;
}
