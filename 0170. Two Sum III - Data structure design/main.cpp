#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: ["TwoSum", "add", "add", "add", "find", "find"]
    [[], [1], [3], [5], [4], [7]]
 * O: [null, null, null, null, true, false]
 * Explanation
    TwoSum twoSum = new TwoSum();
    twoSum.add(1);   // [] --> [1]
    twoSum.add(3);   // [1] --> [1,3]
    twoSum.add(5);   // [1,3] --> [1,3,5]
    twoSum.find(4);  // 1 + 3 = 4, return true
    twoSum.find(7);  // No two integers sum up to 7, return false
 */

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */

class TwoSum {
   public:
    TwoSum() {
    }

    void add(int number) {
        arr.push_back(number);
    }

    bool find(int value) {
        sort(arr.begin(), arr.end());
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            if (arr[l] + arr[r] == value) return true;
            if (arr[l] + arr[r] > value) {
                r--;
            } else {
                l++;
            }
        }
        return false;
    }

   private:
    vector<int> arr;
};

int main(int argc, char const *argv[]) {
    return 0;
}
