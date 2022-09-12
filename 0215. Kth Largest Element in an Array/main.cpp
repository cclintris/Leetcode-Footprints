#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * I: nums = [3,2,1,5,6,4], k = 2
 * O: 5
 *
 * I: nums = [3,2,3,1,2,4,5,5,6], k = 4
 * O: 4
 */

int findKthLargest(vector<int>& nums, int k);

int quickSelect(vector<int>& nums, int ptr, int pivot, int k);

void printVec(vector<int>& vec);

int main(int argc, char const* argv[]) {
    vector<int> nums{3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << findKthLargest(nums, k) << endl;
    return 0;
}

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i : nums) {
        minHeap.push(i);
        if (minHeap.size() > k)
            minHeap.pop();
    }
    return minHeap.top();
}
