#include <iostream>
#include <vector>
using namespace std;

/**
 * I: s = "aab"
 * O: [["a","a","b"],["aa","b"]]
 *
 * I: s = "a"
 * O: [["a"]]
 */

vector<vector<string>> partition(string s);

void dfs(string s, vector<vector<string>>& res, vector<string>& part, int index);

bool isPalindrome(string s, int start, int end);

int main(int argc, char const* argv[]) {
    return 0;
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> part;
    dfs(s, res, part, 0);
    return res;
}

void dfs(string s, vector<vector<string>>& res, vector<string>& part, int index) {
    if (index == s.length()) {
        res.push_back(part);
        return;
    }

    for (int i = index; i < s.length(); i++) {
        if (isPalindrome(s, index, i)) {
            part.push_back(s.substr(index, i - index + 1));
            dfs(s, res, part, i + 1);
            part.pop_back();
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
