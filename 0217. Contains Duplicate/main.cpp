#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * I: nums = [1,2,3,1]
 * O: true
 *
 * I: nums = [1,2,3,4]
 * O: false
 *
 * I: nums = [1,1,1,3,3,4,3,2,4,2]
 * O: true
 */

bool containsDuplicate(vector<int>& nums);

int main(int argc, char const* argv[]) {
    vector<int> nums{1, 2, 3, 1};
    cout << containsDuplicate(nums) << endl;
    return 0;
}

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> set;
    for (int i : nums) {
        if (set.find(i) != set.end()) return true;
        set.insert(i);
    }
    return false;
}
