#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * I: words = ["wrt","wrf","er","ett","rftt"]
 * O: "wertf"
 *
 * I: words = ["z","x"]
 * O: "zx"
 *
 * I: words = ["z","x","z"]
 * O: ""
 */

string alienOrder(vector<string>& words);

int main(int argc, char const* argv[]) {
    vector<string> words{"wrt", "wrf", "er", "ett", "rftt"};
    cout << alienOrder(words) << endl;
    return 0;
}

string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> G;
    for (auto word : words) {
        for (auto c : word) {
            if (G.find(c) == G.end()) G[c] = unordered_set<char>();
        }
    }
    for (int i = 0; i < words.size() - 1; i++) {
        int len = min(words[i].length(), words[i + 1].length());
        if (words[i + 1].length() < words[i].length() && words[i].substr(0, len) == words[i + 1]) return ""; // just to pass all testcases, no need to bother
        for (int j = 0; j < len; j++) {
            char start = words[i][j];
            char end = words[i + 1][j];
            if (start != end) {
                G[start].insert(end);
                break;
            }
        }
    }

    // for (auto adj : G) {
    //     cout << adj.first << " -> ";
    //     for (auto neigh : adj.second) {
    //         cout << neigh;
    //     }
    //     cout << endl;
    // }

    string res = "";
    unordered_map<char, int> inDegree;
    for (auto adj : G) {
        for (auto neigh : adj.second) {
            inDegree[neigh]++;
        }
    }

    // for (auto in : inDegree) {
    //     cout << in.first << ":" << in.second << endl;
    // }

    queue<char> q;
    for (auto adj : G) {
        char start = adj.first;
        if (inDegree.find(start) == inDegree.end()) q.push(start);
    }

    while (!q.empty()) {
        char ch = q.front();
        q.pop();
        res += ch;
        for (auto neigh : G[ch]) {
            inDegree[neigh]--;
            if (inDegree[neigh] == 0) q.push(neigh);
        }
    }
    return res.length() < G.size() ? "" : res;
}
