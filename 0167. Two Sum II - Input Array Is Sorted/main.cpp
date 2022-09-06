#include <iostream>
#include <vector>
using namespace std;

/**
 * I: numbers = [2,7,11,15], target = 9
 * O: [1,2]
 *
 * I: numbers = [2,3,4], target = 6
 * O: [1,3]
 *
 * I: numbers = [-1,0], target = -1
 * O: [1,2]
 */

vector<int> twoSum(vector<int>& numbers, int target);

void printVec(vector<int>& vec);

int main(int argc, char const* argv[]) {
    vector<int> numbers{2, 7, 11, 15};
    int target = 9;
    vector<int> res = twoSum(numbers, target);
    printVec(res);
    return 0;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;
    int l = 0, r = numbers.size() - 1;
    while (l < r) {
        if (numbers[l] + numbers[r] == target) {
            res.push_back(l + 1);
            res.push_back(r + 1);
            break;
        }
        if (numbers[l] + numbers[r] > target) {
            r--;
        } else {
            l++;
        }
    }
    return res;
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
    cout << "]" << endl;
}
