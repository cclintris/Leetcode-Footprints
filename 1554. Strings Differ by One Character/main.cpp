#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * I: dict = ["abcd","acbd", "aacd"]
 * O: 1
 *
 * I: dict = ["ab","cd","yz"]
 * O: 0
 *
 * I: dict = ["abcd","cccc","abyd","abab"]
 * O: 1
 */

bool differByOne(vector<string>& dict);

int main(int argc, char const* argv[]) {
    return 0;
}

// MLE
bool differByOne(vector<string>& dict) {
    int m = dict.size(), n = dict[0].size();
    unordered_set<string> set;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            string mask = dict[i].substr(0, j) + "#" + dict[i].substr(j + 1);
            if (set.find(mask) != set.end()) return true;
            set.insert(mask);
        }
    }
    return false;
}
