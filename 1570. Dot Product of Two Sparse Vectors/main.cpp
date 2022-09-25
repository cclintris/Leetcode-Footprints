#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * I: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
 * O: 8
 *
 * I: nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
 * O: 0
 *
 * I: nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
 * O: 6
 */

class SparseVector {
   public:
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nonZero[i] = nums[i];
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector &vec) {
        int res = 0;
        for (auto it : nonZero) {
            if (vec.nonZero.find(it.first) != vec.nonZero.end()) {
                res += (it.second * vec.nonZero[it.first]);
            }
        }
        return res;
    }

   private:
    unordered_map<int, int> nonZero;
};

int main(int argc, char const *argv[]) {
    return 0;
}
