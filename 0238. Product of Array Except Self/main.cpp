#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [1,2,3,4]
 * O: [24,12,8,6]
 *
 * I: nums = [-1,1,0,-3,3]
 * O: [0,0,9,0,0]
 */

vector<int> productExceptSelf(vector<int>& nums);

void printVec(vector<int>& vec);

int main(int argc, char const* argv[]) {
    vector<int> nums{-1, 1, 0, -3, 3};
    vector<int> res = productExceptSelf(nums);
    printVec(res);
    return 0;
}

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> left_dp(n - 1);
    vector<int> right_dp(n - 1);

    left_dp[0] = nums[0];
    for (int i = 1; i < n - 1; i++) {
        left_dp[i] = left_dp[i - 1] * nums[i];
    }
    right_dp[n - 2] = nums[n - 1];
    for (int i = n - 3; i >= 0; i--) {
        right_dp[i] = right_dp[i + 1] * nums[i + 1];
    }
    // printVec(left_dp);
    // printVec(right_dp);

    vector<int> res(n);
    res[0] = right_dp[0];
    res[n - 1] = left_dp[n - 2];
    for (int i = 1; i < n - 1; i++) {
        res[i] = left_dp[i - 1] * right_dp[i];
    }

    return res;
}

void printVec(vector<int>& vec) {
    int len = vec.size();
    cout << "[";
    for (int i = 0; i < len; i++) {
        if (i == len - 1)
            cout << vec[i];
        else
            cout << vec[i] << ',';
    }
    cout << "]" << endl;
}
