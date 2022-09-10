#include <iostream>
#include <vector>
using namespace std;

/**
 * I: n = 10
 * O: 4
 *
 * I: n = 0
 * O: 0
 *
 * I: n = 1
 * O: 0
 */

int countPrimes(int n);

int main(int argc, char const *argv[]) {
    int n = 10;
    cout << countPrimes(n) << endl;
    return 0;
}

int countPrimes(int n) {
    int count = 0;
    vector<bool> prime(n + 1, true);

    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            count++;

            for (int j = 2 * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
    return count;
}
