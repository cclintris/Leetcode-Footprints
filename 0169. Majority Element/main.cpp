#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * I: nums = [3,2,3]
 * O: 3
 *
 * I: nums = [2,2,1,1,1,2,2]
 * O: 2
 */

int majorityElement(vector<int>& nums);

int main(int argc, char const* argv[]) {
    vector<int> nums{6, 5, 5};
    cout << majorityElement(nums) << endl;
    return 0;
}

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    vector<int>::iterator it = nums.begin();
    while (it != nums.end()) {
        mp[(*it)]++;
        if (mp[(*it)] > (n / 2))
            return *it;
        it++;
    }
    return *it;
}
