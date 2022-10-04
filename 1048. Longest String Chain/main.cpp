#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
* I: words = ["a","b","ba","bca","bda","bdca"]
* O: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
*
* I: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
* O: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
*
* I: words = ["abcd","dbqca"]
* O: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
*/

int longestStrChain(vector<string>& words);

int dfs(unordered_set<string>& wordsPresent, unordered_map<string, int>& memo, string word);

void printMap(unordered_map<string, int>& mp);

int main(int argc, char const* argv[]) {
    vector<string> words{"a", "b", "ba", "bca", "bda", "bdca"};
    cout << longestStrChain(words) << endl;
    return 0;
}

// DP: DFS + memoization
int longestStrChain(vector<string>& words) {
    int res = INT_MIN;
    unordered_map<string, int> memo;
    unordered_set<string> wordsPresent;
    for (string word : words) {
        wordsPresent.insert(word);
    }
    for (string word : wordsPresent) {
        res = max(res, dfs(wordsPresent, memo, word));
        // printMap(memo);
    }
    return res;
}

int dfs(unordered_set<string>& wordsPresent, unordered_map<string, int>& memo, string word) {
    if (memo.find(word) != memo.end()) return memo[word];

    int maxLength = 1;
    for (int i = 0; i < word.size(); i++) {
        string pre = word.substr(0, i) + word.substr(i + 1);
        if (wordsPresent.find(pre) != wordsPresent.end()) {
            maxLength = max(maxLength, 1 + dfs(wordsPresent, memo, pre));
        }
    }
    memo[word] = maxLength;
    return memo[word];
}

void printMap(unordered_map<string, int>& mp) {
    for (auto it : mp) {
        cout << it.first << " : " << it.second << endl;
    }
}
