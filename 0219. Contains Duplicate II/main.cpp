#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * I: nums = [1,2,3,1], k = 3
 * O: true
 *
 * I: nums = [1,0,1,1], k = 1
 * O: true
 *
 * I: nums = [1,2,3,1,2,3], k = 2
 * O: false
 */

bool containsNearbyDuplicate(vector<int>& nums, int k);

int main(int argc, char const* argv[]) {
    vector<int> nums{1, 2, 3, 1, 2, 3};
    int k = 2;
    cout << containsNearbyDuplicate(nums, k) << endl;
    return 0;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
        if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) return true;
        m[nums[i]] = i;
    }
    return false;
}
