#include <iostream>
using namespace std;

/**
 * I: start = "RXXLRXRXL", end = "XRLXXRRLX"
 * O: true
 *
 * I: start = "X", end = "L"
 * O: false
 */

bool canTransform(string start, string end);

int main(int argc, char const *argv[]) {
    string start = "XXXXXLXXXX";
    string end = "LXXXXXXXXX";
    cout << canTransform(start, end) << endl;
    return 0;
}

//  012345678
// "XRXLRXRXL"
// "XRLXXRRLX"
bool canTransform(string start, string end) {
    int i = 0, j = 0;
    while (i < start.size() && j < end.size()) {
        while (start[i] == 'X') i++;
        while (end[j] == 'X') j++;

        if (start[i] != end[j]) return false;
        if (start[i] == 'R' && i > j) return false;
        if (start[i] == 'L' && i < j) return false;
        i++;
        j++;
    }
    while (i < start.size() && start[i] == 'X') i++;
    while (j < end.size() && end[j] == 'X') j++;
    return i == j;
}
