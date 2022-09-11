#include <iostream>
#include <vector>
using namespace std;

/**
 * I: numCourses = 2, prerequisites = [[1,0]]
 * O: true
 *
 * I: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * O: false
 */

bool canFinish(int numCourses, vector<vector<int>>& prerequisites);

bool detectCycle(vector<vector<int>>& graph, vector<int>& visited, int course);

int main(int argc, char const* argv[]) {
    return 0;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> visit(numCourses);
    for (auto a : prerequisites) {
        graph[a[1]].push_back(a[0]);
    }
    for (int i = 0; i < numCourses; ++i) {
        if (!canFinishDFS(graph, visit, i))
            return false;
    }
    return true;
}

bool canFinishDFS(vector<vector<int>>& graph, vector<int>& visit, int i) {
    if (visit[i] == -1) return false;
    if (visit[i] == 1) return true;
    visit[i] = -1;
    for (auto a : graph[i]) {
        if (!canFinishDFS(graph, visit, a))
            return false;
    }
    visit[i] = 1;
    return true;
}
