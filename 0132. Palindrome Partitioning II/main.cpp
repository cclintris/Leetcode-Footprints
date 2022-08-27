#include <iostream>
#include <vector>
using namespace std;

/**
 * I: s = "aab"
 * O: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
 *
 * I: s = "a"
 * O: 0
 *
 * I: s = "ab"
 * O: 1
 */

int minCut(string s);

vector<vector<string>> partition(string s);

void dfs(string s, vector<vector<string>>& res, vector<string>& out, int index);

bool isPalindrome(string s, int start, int end);

int main(int argc, char const* argv[]) {
    return 0;
}

int minCut(string s) {
    vector<vector<string>> res = partition(s);
    int cnt = 0, min = res[0].size();
    for (int i = 1; i < res.size(); i++) {
        if (res[i].size() < min) {
            cnt = i;
            min = res[i].size();
        }
    }
    return res[cnt].size() - 1;
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> out;
    dfs(s, res, out, 0);
    return res;
}

void dfs(string s, vector<vector<string>>& res, vector<string>& out, int index) {
    if (index == s.length()) {
        res.push_back(out);
        return;
    }
    for (int i = index; i < s.length(); i++) {
        if (isPalindrome(s, index, i)) {
            out.push_back(s.substr(index, i - index + 1));
            dfs(s, res, out, i + 1);
            out.pop_back();
        }
    }
}

bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}
