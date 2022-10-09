#include <iostream>
using namespace std;

/**
 * I: graph = [[1,1,0],[0,1,0],[1,1,1]]
 * O: 1
 *
 * I: graph = [[1,0,1],[1,1,0],[0,1,1]]
 * O: -1
 */

/* The knows API is defined for you.
      bool knows(int a, int b); */

bool knows(int a, int b);

int findCelebrity(int n);

int main(int argc, char const *argv[]) {
    return 0;
}

// Brute force
int findCelebrity(int n) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
        flag = false;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                if (!knows(i, j) && knows(j, i)) {
                    flag = true;
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) return i;
    }
    return -1;
}
