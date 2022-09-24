#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

/**
 * I: points = [[1,3],[-2,2]], k = 1
 * O: [[-2,2]]
 * Explanation:
    The distance between (1, 3) and the origin is sqrt(10).
    The distance between (-2, 2) and the origin is sqrt(8).
    Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
    We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
 *
 * I: points = [[3,3],[5,-1],[-2,4]], k = 2
 * O: [[3,3],[-2,4]]
 */

vector<vector<int>> kClosest(vector<vector<int>>& points, int k);

long long int distance(int x, int y);

int main(int argc, char const* argv[]) {
    cout << pow(2, -5) << endl;
    return 0;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> res;
    priority_queue<pair<long long int, vector<int>>, vector<pair<long long int, vector<int>>>, greater<pair<long long int, vector<int>>>> pq;
    for (int i = 0; i < points.size(); i++) {
        pq.push(make_pair(distance(points[i][0], points[i][1]), points[i]));
    }
    while (k > 0) {
        res.push_back(pq.top().second);
        pq.pop();
        k--;
    }
    return res;
}

long long int distance(int x, int y) {
    return pow(x, 2) + pow(y, 2);
}
