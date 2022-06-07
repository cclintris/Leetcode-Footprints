#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: n = 3, k = 3
 * O: "213"
 *
 * I: n = 4, k = 9
 * O: "2314"
 *
 * I: n = 3, k = 1
 * O: "123"
 */

string getPermutation(int n, int k);

// permute STL accepted
string permuteK(string str, int k);

// recursion permute TLE
void permute(vector<string>& vec, string str, string out);

void printV(vector<string> vec);

int main(int argc, char const* argv[]) {
    int n = 3, k = 3;
    cout << getPermutation(n, k) << endl;
    return 0;
}

string getPermutation(int n, int k) {
    string base;
    char c = '1';
    for (int i = 0; i < n; i++)
        base += (c + i);
    return permuteK(base, k);
    // permute(per, base, "");
    // sort(per.begin(), per.end());
}

string permuteK(string str, int k) {
    sort(str.begin(), str.end());
    for (int i = 0; i < k - 1; i++) {
        next_permutation(str.begin(), str.end());
    }
    return str;
}

void permute(vector<string>& vec, string str, string out) {
    if (str.size() == 0) {
        vec.push_back(out);
        return;
    }

    for (int i = 0; i < str.size(); i++) {
        permute(vec, str.substr(1), out + str[0]);
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}

void printV(vector<string> vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        if (i == vec.size() - 1)
            cout << vec[i];
        else
            cout << vec[i] << ",";
    }
    cout << "]\n";
}
