#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * I: numCourses = 2, prerequisites = [[1,0]]
 * O: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
 *
 * I: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * O: [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2.
 * Both courses 1 and 2 should be taken after you finished course 0.
 * So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
 *
 * I: numCourses = 1, prerequisites = []
 * O: [0]
 */

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);

int main(int argc, char const* argv[]) {
    return 0;
}

// Kahn's algorithm
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // Create adjacency list
    vector<vector<int>> G(numCourses, vector<int>{});
    vector<int> inDegree(numCourses, 0);
    int n = prerequisites.size();
    for (int i = 0; i < n; i++) {
        G[prerequisites[i][1]].push_back(prerequisites[i][0]);
        inDegree[prerequisites[i][0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    vector<int> res;
    while (!q.empty()) {
        int front = q.front();
        res.push_back(front);
        q.pop();
        for (auto& it : G[front]) {
            inDegree[it]--;
            if (inDegree[it] == 0) q.push(it);
        }
    }
    if (res.size() != numCourses) res.clear();
    return res;
}
