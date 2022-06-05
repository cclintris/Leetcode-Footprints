#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [2,3,1,1,4]
 * O: true
 *
 * I: nums = [3,2,1,0,4]
 * O: false
 */

bool canJump(vector<int>& nums);

void printV(vector<int>& vec);

int main(int argc, char const* argv[]) {
    int M = 2;
    vector<int> nums(M);
    int arr[] = {0, 2};
    nums.resize(M);
    for (int i = 0; i < M; i++)
        nums.at(i) = arr[i];
    // printV(nums);
    cout << canJump(nums) << endl;
    return 0;
}

bool canJump(vector<int>& nums) {
    int last = nums.size() - 1;
    if (last == 0) return true;
    int l = 0, r = 0;
    while (l < last && r < last) {
        int farthest = l + nums[l];
        for (int i = l + 1; i <= r; i++) {
            int tmp = i + nums[i];
            farthest = max(farthest, tmp);
        }
        if (farthest == r && nums[r] == 0)
            return false;

        l = r + 1;
        r = farthest;
        // cout << "l " << l << endl;
        // cout << "r " << r << endl;
        if (l >= last || r >= last)
            return true;
    }
    return false;
}

void printV(vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        if (i == vec.size() - 1)
            cout << vec.at(i);
        else
            cout << vec.at(i) << ",";
    }
    cout << "]" << endl;
}
