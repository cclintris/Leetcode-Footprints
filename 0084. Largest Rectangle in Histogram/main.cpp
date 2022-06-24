#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
 * I: heights = [2,1,5,6,2,3]
 * O: 10
 * Explanation: The above is a histogram where width of each bar is 1.
   The largest rectangle is shown in the red area, which has an area = 10 units.
 *
 * I: heights = [2,4]
 * O: 4
 */

int largestRectangleArea(vector<int>& heights);

int main(int argc, char const* argv[]) {
    int n = 6;
    int arr[6] = {2, 1, 5, 6, 2, 3};
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
        heights[i] = arr[i];
    cout << largestRectangleArea(heights) << endl;
    return 0;
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

// partial peak algorithm (TLE)
// int largestRectangleArea(vector<int>& heights) {
//     int area = 0;
//     int peak = 0;
//     for (int i = 0; i < heights.size(); i++) {
//         if (i + 1 < heights.size() && heights[i] <= heights[i + 1])
//             continue;

//         int minH = heights[i];
//         for (int j = i; j >= 0; j--) {
//             minH = min(minH, heights[j]);
//             int tmp = minH * (i - j + 1);
//             area = max(tmp, area);
//         }
//     }
//     return area;
// }
