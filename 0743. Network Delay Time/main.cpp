#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

/**
 * I: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
 * O: 2
 *
 * I: times = [[1,2,1]], n = 2, k = 1
 * O: 1
 *
 * I: times = [[1,2,1]], n = 2, k = 2
 * O: -1
 */

int networkDelayTime(vector<vector<int>>& times, int n, int k);

int main(int argc, char const* argv[]) {
    return 0;
}

// BFS + Dijikstra
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    unordered_map<int, vector<pair<int, int>>> G;
    int m = times.size();
    for (auto it : times) {
        G[it[0]].push_back({it[1], it[2]});
    }
    vector<int> dist(n + 1, INT32_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, k));
    dist[k] = 0;
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int w = top.first;
        int v = top.second;
        for (auto n : G[v]) {
            if (w + n.second < dist[n.first]) {
                dist[n.first] = w + n.second;
                pq.push(make_pair(dist[n.first], n.first));
            }
        }
    }

    if (find(dist.begin() + 1, dist.end(), INT32_MAX) != dist.end()) return -1;

    int t = INT32_MIN;
    for (int i = 1; i < dist.size(); i++) {
        if (dist[i] > t) t = dist[i];
    }
    return t;
}
