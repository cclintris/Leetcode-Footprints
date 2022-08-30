#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [1,3,4,2,2]
 * O: 2
 *
 * I: nums = [3,1,3,4,2]
 * O: 3
 */

int findDuplicate(vector<int>& nums);

int main(int argc, char const* argv[]) {
    vector<int> nums{3, 1, 3, 4, 2};
    cout << findDuplicate(nums) << endl;
    return 0;
}

// Floyd's tortoise and hare
int findDuplicate(vector<int>& nums) {
    int fast = nums[0];
    int slow = nums[0];
    do {
        fast = nums[nums[fast]];
        slow = nums[slow];
        if (fast == slow) {
            int entry = nums[0];
            while (entry != slow) {
                entry = nums[entry];
                slow = nums[slow];
            }
            return slow;
        }
    } while (fast != slow);
    return -1;
}
