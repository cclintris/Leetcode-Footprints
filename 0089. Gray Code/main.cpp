#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * I: n = 2
 * O: [0,1,3,2]
 *
 * I: n = 1
 * O: [0,1]
 */

vector<int> grayCode(int n);

void printVec(vector<int>& vec);

int main(int argc, char const* argv[]) {
    int n = 3;
    vector<int> res = grayCode(n);
    printVec(res);
    return 0;
}

// straightforward binary to gray code conversion
// algorithm:
// 以二進制為0值的格雷碼為第零項，第一項改變最右邊的位元，第二項改變右起第一個為1的位元的左邊位元，
// 第三、四項方法同第一、二項，如此反覆，即可排列出n個位元的格雷碼。
vector<int> grayCode(int n) {
    vector<int> gcSeq;
    string base = "";
    for (int i = 0; i < n; i++)
        base += '0';
    gcSeq.push_back(0);
    bool odd = true;
    while (gcSeq.size() != pow(2, n)) {
        if (odd) {
            base[n - 1] = base[n - 1] == '1' ? '0' : '1';
            odd = false;
        } else {
            int first = n - 1;
            while (base[first] != '1')
                first--;
            base[first - 1] = base[first - 1] == '1' ? '0' : '1';
            odd = true;
        }
        int num = stoi(base, 0, 2);
        gcSeq.push_back(num);
    }

    return gcSeq;
}

void printVec(vector<int>& vec) {
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
