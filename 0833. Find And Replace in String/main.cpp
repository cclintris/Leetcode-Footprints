#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * I: s = "abcd", indices = [0, 2], sources = ["a", "cd"], targets = ["eee", "ffff"]
 * O: "eeebffff"
 * Explanation:
    "a" occurs at index 0 in s, so we replace it with "eee".
    "cd" occurs at index 2 in s, so we replace it with "ffff".
 *
 * I: s = "abcd", indices = [0, 2], sources = ["ab","ec"], targets = ["eee","ffff"]
 * O: "eeecd"
 * Explanation:
    "ab" occurs at index 0 in s, so we replace it with "eee".
    "ec" does not occur at index 2 in s, so we do nothing.
 */

string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets);

int main(int argc, char const* argv[]) {
    string s = "abcd";
    vector<int> indices{0, 2};
    vector<string> sources{"a", "cd"};
    vector<string> targets{"eee", "ffff"};
    cout << findReplaceString(s, indices, sources, targets) << endl;
    return 0;
}

string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
    vector<pair<int, int>> v;
    int n = indices.size();
    for (int i = 0; i < n; i++) {
        v.push_back({indices[i], i});
    }
    sort(v.rbegin(), v.rend());
    for (auto p : v) {
        int index = p.first;
        string src = sources[p.second];
        string replace = targets[p.second];
        if (s.substr(index, src.size()) == src) {
            s = s.substr(0, index) + replace + s.substr(index + src.size());
        }
    }
    return s;
}
