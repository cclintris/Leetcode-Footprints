#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * I: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * O: ["AAAAACCCCC","CCCCCAAAAA"]
 *
 * I: s = "AAAAAAAAAAAAA"
 * O: ["AAAAAAAAAA"]
 */

vector<string> findRepeatedDnaSequences(string s);

void printVec(vector<string>& vec);

int main(int argc, char const* argv[]) {
    string s = "AAA";
    vector<string> res = findRepeatedDnaSequences(s);
    printVec(res);
    return 0;
}

vector<string> findRepeatedDnaSequences(string s) {
    if (s.length() < 10) return {};
    unordered_map<string, int> mp;
    vector<string> res;
    for (int i = 0; i <= s.length() - 10; i++) {
        mp[s.substr(i, 10)]++;
    }
    for (auto it : mp) {
        if (it.second > 1) res.push_back(it.first);
    }
    return res;
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
