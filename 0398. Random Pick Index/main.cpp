#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * I: ["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
 * O: [null, 4, 0, 2]
 Explanation
    Solution solution = new Solution([1, 2, 3, 3, 3]);
    solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
    solution.pick(1); // It should return 0. Since in the array only nums[0] is equal to 1.
    solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
 */

class Solution {
   public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        int l = mp[target].size();
        return mp[target][rand() % l];
    }

   private:
    unordered_map<int, vector<int>> mp;
};

int main(int argc, char const* argv[]) {
    return 0;
}
