#include <iostream>
#include <random>
#include <vector>
using namespace std;

// Prefix sum algorithm
class Solution {
   public:
    Solution(vector<int>& w) {
        int n = w.size();
        prefixSums.resize(n);
        int accSum = 0;
        for (int i = 0; i < n; i++) {
            accSum += w[i];
            prefixSums[i] = accSum;
        }
        totalSum = accSum;
    }

    int pickIndex() {
        // (double)rand() / (double)RAND_MAX => generate 0-1 random in C++
        double target = (double)rand() / (double)RAND_MAX * totalSum;
        int i = 0;
        for (; i < prefixSums.size(); i++) {
            if (target < prefixSums[i])
                return i;
        }
        return i - 1;
    }

    // Optimized binary search algorithm
    int pickIndex() {
        int low = 0, high = prefixSums.size() - 1;
        double target = (double)rand() / (double)RAND_MAX * totalSum;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (target > prefixSums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

   private:
    vector<int> prefixSums;
    int totalSum = 0;
};

int main(int argc, char const* argv[]) {
    double r = rand() / RAND_MAX;
    cout << r << endl;
    return 0;
}
