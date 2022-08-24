#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

/**
 * I: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
 * O: 5
 * Explanation: One shortest transformation sequence is
 * "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
 *
 * I: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
 * O: 0
 * Explanation: The endWord "cog" is not in wordList,
 * therefore there is no valid transformation sequence.
 */

int ladderLength(string beginWord, string endWord, vector<string>& wordList);

int main(int argc, char const* argv[]) {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    cout << ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if (!count(wordList.begin(), wordList.end(), endWord))
        return 0;

    // Build an Adjacent List for Graph representation
    wordList.push_back(beginWord);
    int n = wordList.size(), m = wordList[0].size();
    map<string, vector<string>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string wildcard = wordList[i].substr(0, j) + "*" + wordList[i].substr(j + 1, m - j - 1);
            mp[wildcard].push_back(wordList[i]);
        }
    }

    // BFS
    set<string> visited;
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    while (!q.empty()) {
        pair<string, int> cur = q.front();
        q.pop();
        for (int i = 0; i < m; i++) {
            string wildcard = cur.first.substr(0, i) + "*" + cur.first.substr(i + 1, m - i - 1);
            for (auto word : mp[wildcard]) {
                if (visited.find(word) == visited.end()) {
                    if (word == endWord)
                        return cur.second + 1;
                    q.push({word, cur.second + 1});
                    visited.insert(word);
                }
            }
        }
    }
    return 0;
}
