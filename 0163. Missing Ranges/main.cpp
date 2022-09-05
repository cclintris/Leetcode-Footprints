#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * I: nums = [0,1,3,50,75], lower = 0, upper = 99
 * O: ["2","4->49","51->74","76->99"]
 * Explanation: The ranges are:
    [2,2] --> "2"
    [4,49] --> "4->49"
    [51,74] --> "51->74"
    [76,99] --> "76->99"
 *
 * I: nums = [-1], lower = -1, upper = -1
 * O: []
 * Explanation: There are no missing ranges since there are no missing numbers.
 *
 */

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper);

void pushString(vector<string>& res, int start, int end);

void printVec(vector<string>& vec);

int main(int argc, char const* argv[]) {
    vector<int> nums{-1};
    int lower = -1, upper = -1;
    vector<string> res = findMissingRanges(nums, lower, upper);
    printVec(res);
    return 0;
}

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> res;
    int n = nums.size();
    if (n == 0) {
        pushString(res, lower, upper);
    } else {
        if (nums[0] > lower) {
            pushString(res, lower, nums[0] - 1);
        }
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] != 1) {
                pushString(res, nums[i] + 1, nums[i + 1] - 1);
            }
        }
        if (nums[n - 1] < upper) {
            pushString(res, nums[n - 1] + 1, upper);
        }
    }
    return res;
}

void pushString(vector<string>& res, int start, int end) {
    if (start == end) {
        res.push_back(to_string(start));
    } else {
        res.push_back(to_string(start) + "->" + to_string(end));
    }
}

void printVec(vector<string>& vec) {
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
