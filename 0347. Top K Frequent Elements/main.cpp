#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

/**
 * I: nums = [1,1,1,2,2,3], k = 2
 * O: [1,2]
 *
 * I: nums = [1], k = 1
 * O: [1]
 */

vector<int> topKFrequent(vector<int>& nums, int k);

int main(int argc, char const* argv[]) {
    return 0;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.find(nums[i]) == mp.end()) {
            mp[nums[i]] = 1;
        } else {
            mp[nums[i]]++;
        }
    }
    priority_queue<pair<int, int>> pq;
    for (auto it : mp) {
        pair<int, int> unit = make_pair(it.second, it.first);
        pq.push(unit);
    }
    vector<int> res;
    while (k > 0) {
        res.push_back(pq.top().second);
        pq.pop();
        k--;
    }
    return res;
}
