#include <deque>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * I: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
 * O: true
 *
 * I: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
 * O: false
 */

bool validTree(int n, vector<vector<int>>& edges);

void dfs(vector<vector<int>>& G, unordered_set<int>& set, int& visited, bool& isCycle, int cur, int parent);

int main(int argc, char const* argv[]) {
    return 0;
}

// DFS
bool validTree(int n, vector<vector<int>>& edges) {
    // Create adjacency list of graph representation
    vector<vector<int>> G(n, vector<int>{});
    for (auto& it : edges) {
        G[it[0]].push_back(it[1]);
        G[it[1]].push_back(it[0]);
    }
    int visited = 0;
    bool isCycle = false;
    unordered_set<int> set;
    dfs(G, set, visited, isCycle, 0, -1);
    return visited == n && !isCycle;
}

void dfs(vector<vector<int>>& G, unordered_set<int>& set, int& visited, bool& isCycle, int cur, int parent) {
    visited++;
    set.insert(cur);
    for (auto& it : G[cur]) {
        if (it == parent) continue;
        if (set.find(it) != set.end()) {
            isCycle = true;
        } else {
            dfs(G, set, visited, isCycle, it, cur);
        }
    }
    return;
}

// BFS
bool validTree(int n, vector<vector<int>>& edges) {
    // Create adjacency list of graph representation
    vector<vector<int>> G(n, vector<int>{});
    for (auto& it : edges) {
        G[it[0]].push_back(it[1]);
        G[it[1]].push_back(it[0]);
    }
    deque<int> dq;
    dq.push_back(0);
    int cnt = 0;
    unordered_set<int> visited;
    unordered_map<int, int> parent;
    // bool isCycle = false;
    while (!dq.empty()) {
        int cur = dq.front();
        visited.insert(cur);
        cnt++;
        for (auto& it : G[cur]) {
            if (it == parent[cur]) continue;
            if (visited.find(it) != visited.end()) {
                // isCycle = true;
                return false;
            }
            parent[it] = cur;
            dq.push_back(it);
        }
        dq.pop_front();
    }
    return cnt == n;
}
