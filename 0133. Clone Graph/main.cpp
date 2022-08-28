#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * I: adjList = [[2,4],[1,3],[2,4],[1,3]]
 * O: [[2,4],[1,3],[2,4],[1,3]]
 * Explanation: There are 4 nodes in the graph.
    1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
    2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
    3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
    4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
 *
 * I: adjList = [[]]
 * O: [[]]
 * Explanation: Note that the input contains one empty list.
 * The graph consists of only one node with val = 1 and it does not have any neighbors.
 *
 * I: adjList = []
 * O: []
 * Explanation: This an empty graph, it does not have any nodes.
 */

struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* node);

Node* dfs(Node* node, unordered_map<Node*, Node*>& mp);

int main(int argc, char const* argv[]) {
    return 0;
}

Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> mp;
    if (node == NULL) return NULL;
    if (node->neighbors.size() == 0) {
        Node* clone = new Node(node->val);
        return clone;
    }
    return dfs(node, mp);
}

Node* dfs(Node* node, unordered_map<Node*, Node*>& mp) {
    vector<Node*> neighbors;
    Node* clone = new Node(node->val);
    mp[node] = clone;
    for (auto it : node->neighbors) {
        if (mp.find(it) != mp.end()) {  // already cloned and because stored in map
            neighbors.push_back(mp[it]);
        } else {
            neighbors.push_back(dfs(it, mp));
        }
    }
    clone->neighbors = neighbors;
    return clone;
}
