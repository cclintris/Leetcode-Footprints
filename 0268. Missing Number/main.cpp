#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [3,0,1]
 * O: 2
 *
 * I: nums = [0,1]
 * O: 2
 *
 * I: nums = [9,6,4,2,3,5,7,0,1]
 * O: 8
 */

int missingNumber(vector<int>& nums);

int main(int argc, char const* argv[]) {
    return 0;
}

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    vector<int> arr(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (find(nums.begin(), nums.end(), i) != nums.end()) arr[i]++;
    }
    for (int i = 0; i < n + 1; i++) {
        if (arr[i] == 0) return i;
    }
}
