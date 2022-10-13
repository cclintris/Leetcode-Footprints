#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: arr = [4,2,1,3]
 * O: [[1,2],[2,3],[3,4]]
 *
 * I: arr = [1,3,6,10,15]
 * O: [[1,3]]
 *
 * I: arr = [3,8,-10,23,19,-4,-14,27]
 * O: [[-14,-10],[19,23],[23,27]]
 */

vector<vector<int>> minimumAbsDifference(vector<int>& arr);

int main(int argc, char const* argv[]) {
    return 0;
}

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    int curMin = INT_MAX;
    for (int i = 0; i < arr.size() - 1; i++) {
        int diff = arr[i + 1] - arr[i];
        if (diff == curMin) {
            res.push_back({arr[i], arr[i + 1]});
        } else {
            if (diff < curMin) {
                res.clear();
                res.push_back({arr[i], arr[i + 1]});
                curMin = diff;
            }
        }
    }
    return res;
}
