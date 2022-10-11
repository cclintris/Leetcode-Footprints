#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [0,1,0,3,12]
 * O: [1,3,12,0,0]
 *
 * I: nums = [0]
 * O: [0]
 */

void moveZeroes(vector<int>& nums);

int main(int argc, char const* argv[]) {
    return 0;
}

void moveZeroes(vector<int>& nums) {
    int numZeroes = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        numZeroes += (nums[i] == 0);
    }
    vector<int> tmp;
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) tmp.push_back(nums[i]);
    }
    while (numZeroes--) {
        tmp.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        nums[i] = tmp[i];
    }
}
