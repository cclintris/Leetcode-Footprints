#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/**
 * I: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
 * O: false
 *
 * I: graph = [[1,3],[0,2],[1,3],[0,2]]
 * O: true
 */

bool isBipartite(vector<vector<int>>& graph);

bool dfs(vector<vector<int>>& graph, vector<int>& color, int cur);

int main(int argc, char const* argv[]) {
    vector<vector<int>> graph{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << isBipartite(graph) << endl;
    return 0;
}

// DFS: stack
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            stack<int> st;
            color[i] = 0;
            st.push(i);
            while (!st.empty()) {
                int visit = st.top();
                st.pop();
                for (int neigh : graph[visit]) {
                    if (color[neigh] == -1) {
                        color[neigh] = color[visit] ^ 1;  // XOR
                        st.push(neigh);
                    } else {
                        if (color[neigh] == color[visit]) return false;
                    }
                }
            }
        }
    }
    return true;
}

// DFS: recursion
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!dfs(graph, color, i)) return false;
        }
    }
    return true;
}

bool dfs(vector<vector<int>>& graph, vector<int>& color, int cur) {
    if (color[cur] == -1) color[cur] = 0;
    for (int neigh : graph[cur]) {
        if (color[neigh] == -1) {
            color[neigh] = color[cur] ^ 1;
            if (!dfs(graph, color, neigh)) return false;
        } else {
            if (color[neigh] == color[cur]) return false;
        }
    }
    return true;
}

// BFS
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int front = q.front();
                q.pop();
                for (int neigh : graph[front]) {
                    if (color[neigh] == -1) {
                        color[neigh] = color[front] ^ 1;
                        q.push(neigh);
                    } else {
                        if (color[neigh] == color[front]) return false;
                    }
                }
            }
        }
    }
    return true;
}
