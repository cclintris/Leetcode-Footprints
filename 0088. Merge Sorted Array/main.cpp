#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * I: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * O: [1,2,2,3,5,6]
 * Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
   The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
 *
 * I: nums1 = [1], m = 1, nums2 = [], n = 0
 * O: [1]
 * Explanation: The arrays we are merging are [1] and [].
   The result of the merge is [1].
 *
 * I: nums1 = [0], m = 0, nums2 = [1], n = 1
 * O: [1]
 * Explanation: The arrays we are merging are [] and [1].
   The result of the merge is [1].
   Note that because m = 0, there are no elements in nums1.
   The 0 is only there to ensure the merge result can fit in nums1.
 */

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

void printVec(vector<int>& vec);

int main(int argc, char const* argv[]) {
    int m = 1, n = 1;
    int arr1[2] = {2, 0};
    int arr2[1] = {1};
    vector<int> nums1(m + n);
    vector<int> nums2(n);
    for (int i = 0; i < m + n; i++)
        nums1[i] = arr1[i];
    for (int i = 0; i < n; i++)
        nums2[i] = arr2[i];
    printVec(nums1);
    printVec(nums2);
    merge(nums1, m, nums2, n);
    printVec(nums1);
    return 0;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    unordered_map<int, int> ht;
    vector<int> vec;
    for (int i = 0; i < m; i++) {
        if (ht.find(nums1[i]) == ht.end()) {
            ht[nums1[i]] = 1;
            vec.push_back(nums1[i]);
        } else {
            ht[nums1[i]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ht.find(nums2[i]) == ht.end()) {
            ht[nums2[i]] = 1;
            vec.push_back(nums2[i]);
        } else {
            ht[nums2[i]]++;
        }
    }
    sort(vec.begin(), vec.end());
    int index = 0;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < ht[vec[i]]; j++) {
            nums1[index++] = vec[i];
        }
    }
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
    cout << "]\n";
}