#include <deque>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * O: [3,3,5,5,6,7]
 * Explanation:
    Window position                Max
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
    1 [3  -1  -3] 5  3  6  7       3
    1  3 [-1  -3  5] 3  6  7       5
    1  3  -1 [-3  5  3] 6  7       5
    1  3  -1  -3 [5  3  6] 7       6
    1  3  -1  -3  5 [3  6  7]      7
 *
 * I: nums = [1], k = 1
 * O: [1]
 */

vector<int> maxSlidingWindow(vector<int>& nums, int k);

int main(int argc, char const* argv[]) {
    return 0;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // dequeue is there so that we can perform push and pop from both the ends
    deque<int> dq;
    vector<int> ans;

    // pushing elements of first window into dequeue but what we will be doing is
    // we will be storing them in decreasing order
    for (int i = 0; i < k; i++) {
        // what we are doing is, we are checking that the element we have inserted
        // previously, is greater than our current adding element or not
        // if current element is greater than the last element in dequeue, we will remove
        // last element from dequeue, as we are storing in decreasing order..
        // if any element which is greater than the last element, that shows that last
        // element will never be the ans, so just remove it, only add those elements
        // which is smaller than last elements
        // that will maintain the sequence of decreasing order
        // perform this until dequeue is empty, as once its empty, you can't perform pop
        while (!dq.empty() && dq.back() < nums[i]) {
            dq.pop_back();
        }

        // storing elements from back end
        // if current element is lesser than previous element, add it to dequeue
        dq.push_back(nums[i]);
    }
    // first max num from first window
    // dq.front will give max as decreasing order
    ans.push_back(dq.front());

    // now visiting all the other windows
    // not forming windows of k size as we do in brute force, besides what we do is
    // for each iteration, we keep adding 1 element at back while removing 1 element from front
    // this will keep behaving like a window
    for (int i = k; i < nums.size(); i++) {
        // for checking that the first element of a window, prev windows max element
        // is still present in turn of next window or not
        // if present, remove it
        if (dq.front() == nums[i - k]) {
            dq.pop_front();
        }

        // we are doing the same thing as we have done above
        // checking for a window, not satisfy -> pop, satisfy-> push
        while (!dq.empty() && dq.back() < nums[i]) {
            dq.pop_back();
        }
        dq.push_back(nums[i]);
        // adding max of a window
        ans.push_back(dq.front());
    }
    return ans;
}