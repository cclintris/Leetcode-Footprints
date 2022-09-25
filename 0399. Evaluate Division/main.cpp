#include <deque>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

/**
 * I: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 * O: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
 *
 * I: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 * O: [3.75000,0.40000,5.00000,0.20000]
 *
 * I: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
 * O: [0.50000,2.00000,-1.00000,-1.00000]
 */

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries);

int main(int argc, char const* argv[]) {
    return 0;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    vector<double> res;
    unordered_map<string, unordered_map<string, double>> g;

    // create adjacency list graph representation
    for (int i = 0; i < equations.size(); i++) {
        g[equations[i][0]][equations[i][1]] = values[i];
        g[equations[i][0]][equations[i][0]] = 1.0;
        g[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        g[equations[i][1]][equations[i][1]] = 1.0;
    }

    // BFS
    for (int i = 0; i < queries.size(); i++) {
        vector<string> query = queries[i];
        deque<pair<string, double>> dq;
        unordered_set<string> visited{query[0]};
        dq.push_back(make_pair(query[0], 1.0));
        bool isFound = false;
        if (g.find(query[0]) == g.end()) {
            res.push_back(-1.0);
            continue;
        }
        while (!dq.empty() && !isFound) {
            auto t = dq.front();
            if (t.first == query[1]) {
                isFound = true;
                res.push_back(t.second);
                break;
            }
            for (auto adj : g[t.first]) {
                if (visited.find(adj.first) != visited.end()) continue;
                visited.insert(adj.first);
                dq.push_back(make_pair(adj.first, adj.second * t.second));
            }
            dq.pop_front();
        }
        if (!isFound) res.push_back(-1.0);
    }
    return res;
}
