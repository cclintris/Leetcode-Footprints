#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
 * O: 6
 *
 * I: books = [[1,3],[2,4],[3,2]], shelfWidth = 6
 * O: 4
 */

int minHeightShelves(vector<vector<int>>& books, int shelfWidth);

int main(int argc, char const* argv[]) {
    return 0;
}

int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    int n = books.size();
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        int width = books[i - 1][0];
        int height = books[i - 1][1];
        dp[i] = dp[i - 1] + height;
        for (int j = i - 2; j >= 0 && width + books[j][0] <= shelfWidth; j--) {
            height = max(height, books[j][1]);
            width += books[j][0];
            dp[i] = min(dp[i], dp[j] + height);
        }
    }
    return dp[n];
}
