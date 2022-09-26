#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: heights = [4,2,3,1]
 * O: [0,2,3]
 * Explanation: Building 1 (0-indexed) does not have an ocean view because building 2 is taller.
 *
 * I: heights = [4,3,2,1]
 * O: [0,1,2,3]
 * Explanation: All the buildings have an ocean view.
 *
 * I: heights = [1,3,2,4]
 * O: [3]
 * Explanation: Only building 3 has an ocean view.
 */

vector<int> findBuildings(vector<int>& heights);

int main(int argc, char const* argv[]) {
    return 0;
}

vector<int> findBuildings(vector<int>& heights) {
    int n = heights.size();
    vector<int> res;
    int max = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (heights[i] > max) {
            res.push_back(i);
            max = heights[i];
        }
    }
    sort(res.begin(), res.end());
    return res;
}
