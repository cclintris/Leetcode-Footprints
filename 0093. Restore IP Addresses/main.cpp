#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * I: s = "25525511135"
 * O: ["255.255.11.135","255.255.111.35"]
 *
 * I: s = "0000"
 * O: ["0.0.0.0"]
 *
 * I: s = "101023"
 * O: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 */

vector<string> restoreIpAddresses(string s);

void dfs(string s, int k, string out, vector<string>& res);

bool isValid(string s);

void printVec(vector<string>& vec);

int main(int argc, char const* argv[]) {
    string s = "00000";
    vector<string> res = restoreIpAddresses(s);
    printVec(res);
    return 0;
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    dfs(s, 0, "", res);
    return res;
}

void dfs(string s, int k, string out, vector<string>& res) {
    if (k == 4) {
        if (s.empty())
            res.push_back(out);
        return;
    }
    for (int i = 1; i <= 3; i++) {
        if (s.length() >= i && isValid(s.substr(0, i))) {
            string tmp = k < 3 ? s.substr(0, i) + '.' : s.substr(0, i);
            dfs(s.substr(i), k + 1, out + tmp, res);
        }
    }
    return;
}

bool isValid(string s) {
    if (s.empty() || s.length() > 3 || s.length() > 1 && s[0] == '0') return false;
    int num = stoi(s);
    return num <= 255 && num >= 0;
}

void printVec(vector<string>& vec) {
    int len = vec.size();
    cout << "[";
    for (int i = 0; i < len; i++) {
        if (i == len - 1)
            cout << vec[i];
        else
            cout << vec[i] << ',';
    }
    cout << "]\n";
}
