#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

/**
 * I: points = [[1,1],[2,2],[3,3]]
 * O: 3
 *
 * I: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * O: 4
 */

int maxPoints(vector<vector<int>>& points);

// // Euclidean GCD algorithm
int gcd(int a, int b);

int main(int argc, char const* argv[]) {
    vector<vector<int>> points{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    cout << maxPoints(points) << endl;
    // int a = -6, b = -24;
    // cout << __algo_gcd(a, b) << endl;
    return 0;
}

int maxPoints(vector<vector<int>>& points) {
    int res = 0;
    for (int i = 0; i < points.size(); i++) {
        map<pair<int, int>, int> mp;
        // int duplicate = 1;
        for (int j = i + 1; j < points.size(); j++) {
            int dx = points[i][0] - points[j][0];
            int dy = points[i][1] - points[j][1];
            // if (dx == 0 && dy == 0) {
            //     duplicate++;
            //     continue;
            // }
            int d = gcd(dx, dy);
            mp[{dx / d, dy / d}]++;
        }
        // res = max(res, duplicate);
        for (map<pair<int, int>, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            res = max(res, it->second);
            // res = max(res, it->second + duplicate);
        }
    }
    return res;
}

// // Euclidean GCD algorithm
// supoprts positive and negative numbers
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}
