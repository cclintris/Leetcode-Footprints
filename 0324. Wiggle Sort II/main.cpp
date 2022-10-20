#include <iostream>
#include <vector>
using namespace std;

/**
* I: nums = [1,5,1,1,6,4]
* O: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.
*
* I: nums = [1,3,2,2,3,1]
* O: [2,3,1,3,1,2]
*
* I:
* O:
*/

void wiggleSort(vector<int>& nums);

int main(int argc, char const* argv[]) {
    return 0;
}

void wiggleSort(vector<int>& nums) {
    vector<int> tmp = nums;
    int n = nums.size(), k = (n + 1) / 2, j = n;
    sort(tmp.begin(), tmp.end());
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (flag) {
            nums[i] = tmp[--k];
        } else {
            nums[i] = tmp[--j];
        }
        flag = !flag;
    }
}
