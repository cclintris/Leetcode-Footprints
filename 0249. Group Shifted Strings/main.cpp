#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * I: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
 * O: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
 *
 * I: strings = ["a"]
 * O: [["a"]]
 */

vector<vector<string>> groupStrings(vector<string>& strings);

string degradeToFirst(string s);

int main(int argc, char const* argv[]) {
    string s = "ba";
    cout << degradeToFirst(s) << endl;
    return 0;
}

vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> res;
    unordered_map<string, int> seq;
    int index = 0;
    for (int i = 0; i < strings.size(); i++) {
        string key = degradeToFirst(strings[i]);
        if (seq.find(key) == seq.end()) {
            seq[key] = index++;
            res.push_back({});
        }
        res[seq[key]].push_back(strings[i]);
    }
    return res;
}

string degradeToFirst(string s) {
    if (s[0] == 'a') return s;
    int n = s.length();
    string res = "";
    int gap = 'a' - (int)s[0];
    for (int i = 0; i < n; i++) {
        int tmp = (int)s[i] + gap;
        res += tmp < 97 ? char(122 - (97 - tmp) + 1) : char(tmp);
    }
    return res;
}
