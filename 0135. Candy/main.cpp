#include <iostream>
#include <vector>
using namespace std;

/**
 * I: ratings = [1,0,2]
 * O: 5
 * Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
 *
 * I: ratings = [1,2,2]
 * O: 4
 * Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
    The third child gets 1 candy because it satisfies the above two conditions.
 */

int candy(vector<int>& ratings);

void printVec(vector<int>& vec);

int main(int argc, char const* argv[]) {
    vector<int> ratings{1, 3, 4, 5, 2};
    cout << candy(ratings) << endl;
    return 0;
}

int candy(vector<int>& ratings) {
    printVec(ratings);
    int n = ratings.size();
    vector<int> alloc(n, 1);
    for (int i = 0; i < n - 1; i++) {
        if (ratings[i + 1] > ratings[i]) {
            alloc[i + 1] = alloc[i] + 1;
        }
    }
    // printVec(alloc);
    for (int i = n - 1; i > 0; i--) {
        if (ratings[i - 1] > ratings[i]) {
            alloc[i - 1] = alloc[i] + 1 < alloc[i - 1] ? alloc[i - 1] : alloc[i] + 1;
        }
    }
    // printVec(alloc);
    int res = 0;
    for (int i = 0; i < n; i++)
        res += alloc[i];
    return res;
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
    cout << "]" << endl;
}
