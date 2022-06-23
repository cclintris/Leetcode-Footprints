#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [2,5,6,0,0,1,2], target = 0
 * O: true
 *
 * I: nums = [2,5,6,0,0,1,2], target = 3
 * O: false
 */

bool search(vector<int>& nums, int target);

int main(int argc, char const* argv[]) {
    return 0;
}

bool search(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (target == nums[i])
            return true;
    }
    return false;
}
