#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * I: n = 10
 * O: 12
 *
 * I: n = 1
 * O: 1
 *
 * I:
 * O:
 */

int nthUglyNumber(int n);

int main(int argc, char const *argv[]) {
    int n = 10;
    cout << nthUglyNumber(n) << endl;
    return 0;
}

int nthUglyNumber(int n) {
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    minHeap.push(1);
    for (int i = 1; i < n; i++) {
        long long top = minHeap.top();
        minHeap.pop();
        while (minHeap.top() == top && !minHeap.empty()) {
            minHeap.pop();
        }
        minHeap.push(top * 2);
        minHeap.push(top * 3);
        minHeap.push(top * 5);
    }
    return minHeap.top();
}
