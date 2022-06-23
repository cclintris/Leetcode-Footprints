#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * I: nums = [1,1,1,2,2,3]
 * O: 5, nums = [1,1,2,2,3,_]
 * Explanation:
 * Your function should return k = 5,
 * with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
 * It does not matter what you leave beyond the returned k (hence they are underscores).
 *
 * I: nums = [0,0,1,1,1,1,2,3,3]
 * O: 7, nums = [0,0,1,1,2,3,3,_,_]
 * Explanation: Your function should return k = 7,
 * with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
 * It does not matter what you leave beyond the returned k (hence they are underscores).
 *
 */

int removeDuplicates(vector<int>& nums);

void printV(vector<int> vec);

int main(int argc, char const* argv[]) {
    int n = 9;
    int arr[9] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        nums[i] = arr[i];
    int k = removeDuplicates(nums);
    cout << k << endl;
    printV(nums);
    return 0;
}

int removeDuplicates(vector<int>& nums) {
    int k = 0;
    unordered_map<int, int> ht;
    vector<int> vec;
    for (int i = 0; i < nums.size(); i++) {
        if (ht.find(nums[i]) == ht.end()) {
            ht[nums[i]] = 1;
            vec.push_back(nums[i]);
        } else {
            ht[nums[i]]++;
        }
    }

    int ptr = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (ht[vec[i]] >= 2) {
            k += 2;
            nums[ptr] = vec[i];
            nums[ptr + 1] = vec[i];
            ptr += 2;
        } else {
            k += 1;
            nums[ptr] = vec[i];
            ptr += 1;
        }
    }

    return k;
}

void printV(vector<int> vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        if (i != vec.size() - 1)
            cout << vec[i] << ",";
        else
            cout << vec[i];
    }
    cout << "]" << endl;
}
