#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * O: [[1,6],[8,10],[15,18]]
 *
 * I: intervals = [[1,4],[4,5]]
 * O: [[1,5]]
 */

vector<vector<int> > merge(vector<vector<int> >& intervals);

void printV(vector<vector<int> >& vec);

int main(int argc, char const* argv[]) {
    int m = 4, n = 2;
    int arr[4][2] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int> > intervals;
    intervals.resize(m);
    for (int i = 0; i < m; i++) {
        intervals[i].resize(n);
        intervals[i][0] = arr[i][0];
        intervals[i][1] = arr[i][1];
    }
    vector<vector<int> > ret = merge(intervals);
    printV(ret);
    return 0;
}

vector<vector<int> > merge(vector<vector<int> >& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int> > ret;
    for (int i = 0; i < intervals.size(); i++) {
        if (ret.empty() || ret.back()[1] < intervals[i][0]) {
            ret.push_back(intervals[i]);
        } else {
            ret.back()[1] = max(ret.back()[1], intervals[i][1]);
        }
    }
    return ret;
}

void printV(vector<vector<int> >& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << "[" << vec[i][0] << "," << vec[i][1] << "]";
        if (i != vec.size() - 1)
            cout << ",";
    }
    cout << "]";
}
