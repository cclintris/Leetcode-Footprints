#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * I: matrix = [["1","0","1","0","0"],
 *              ["1","0","1","1","1"],
 *              ["1","1","1","1","1"],
 *              ["1","0","0","1","0"]]
 * O: 6
 *
 * I: matrix = [["0"]]
 * O: 0
 *
 * I: matrix = [["0"]]
 * O: 1
 */

int maximalRectangle(vector<vector<char> >& matrix);

int largestRectangleArea(vector<int>& heights);

void printV(vector<int> vec);

int main(int argc, char const* argv[]) {
    int n = 1, m = 1;
    vector<vector<char> > matrix(n, vector<char>(m));
    char arr[1][1] = {{'0'}};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            matrix[i][j] = arr[i][j];
    }
    cout << maximalRectangle(matrix) << endl;
    return 0;
}

int maximalRectangle(vector<vector<char> >& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    if (n == 1 && m == 1) {
        if (matrix[0][0] == '1')
            return 1;
        else
            return 0;
    }

    string cmp = "";
    string tmp = "";
    for (int i = 0; i < n; i++)
        cmp += '0';

    for (int i = n - 1; i >= 0; i--) {
        tmp += matrix[i][0];
    }
    if (tmp == cmp) {
        for (int i = 0; i < n; i++)
            matrix[i].erase(matrix[i].begin());
    }
    tmp = "";
    m = matrix[0].size();
    for (int i = n - 1; i >= 0; i--) {
        tmp += matrix[i][m - 1];
    }
    if (tmp == cmp) {
        for (int i = 0; i < n; i++)
            matrix[i].pop_back();
    }

    n = matrix.size(), m = matrix[0].size();
    tmp = "", cmp = "";
    vector<int> rec(m);
    int base = 0;
    for (int i = 0; i < m; i++)
        cmp += '1';

    for (int i = n - 1; i >= 0; i--) {
        string tmp = "";
        for (int j = 0; j < m; j++) {
            tmp += matrix[i][j];
        }
        if (tmp == cmp) {
            base = i;
            break;
        }
    }

    // cout << "base " << base << endl;

    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = base; j >= 0; j--) {
            if (matrix[j][i] != '1') {
                rec[i] = count;
                break;
            } else {
                count++;
                if (j == 0) {
                    rec[i] = count;
                    break;
                }
            }
        }
    }

    // printV(rec);

    return largestRectangleArea(rec);
}

// stack
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;

    int n = heights.size(), ans = 0;
    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        while (!st.empty() && heights[st.top()] >= h) {
            int index = st.top();
            st.pop();
            int area = st.empty() ? i * heights[index] : (i - 1 - st.top()) * heights[index];
            ans = max(area, ans);
        }
        st.push(i);
    }
    return ans;
}

void printV(vector<int> vec) {
    int l = vec.size();
    cout << "[";
    for (int i = 0; i < l; i++) {
        if (i == l - 1)
            cout << vec[i];
        else
            cout << vec[i] << ",";
    }
    cout << "]" << endl;
}
