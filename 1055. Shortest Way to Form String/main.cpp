#include <iostream>
#include <string>
using namespace std;

/**
 * I: source = "abc", target = "abcbc"
 * O: 2
 *
 * I: source = "abc", target = "acdbc"
 * O: -1
 *
 * I: source = "xyz", target = "xzyxz"
 * O: 3
 */

int shortestWay(string source, string target);

int main(int argc, char const *argv[]) {
    string source = "abc";
    string target = "acdbc";
    cout << shortestWay(source, target) << endl;
    return 0;
}

// greedy + two pointer
int shortestWay(string source, string target) {
    int l1 = source.size(), l2 = target.size();
    int p1 = 0, p2 = 0;
    int res = 0;
    bool flag = false;
    while (p2 < l2) {
        if (p1 >= l1) {
            if (!flag) return -1;
            flag = false;
            p1 = 0;
            res++;
        }
        if (source[p1] == target[p2]) {
            flag = true;
            p2++;
        }
        p1++;
    }

    return res + 1;
}
