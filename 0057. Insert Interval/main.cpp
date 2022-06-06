#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * O: [[1,5],[6,9]]
 *
 * I: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * O: [[1,2],[3,10],[12,16]]
 * Explanation:
 * Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 */

vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval);

void printV(vector<vector<int> >& vec);

int main(int argc, char const* argv[]) {
    int m = 5, n = 2;
    int arr[5][2] = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<vector<int> > intervals;
    intervals.resize(m);
    for (int i = 0; i < m; i++) {
        intervals[i].resize(n);
        intervals[i][0] = arr[i][0];
        intervals[i][1] = arr[i][1];
    }

    vector<int> newInterval;
    int arr1[] = {4, 8};
    for (int i = 0; i < 2; i++)
        newInterval.push_back(arr1[i]);

    vector<vector<int> > vec = insert(intervals, newInterval);
    printV(vec);
    return 0;
}

vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
    vector<vector<int> > ret;
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size(); i++) {
        if (ret.empty() || intervals[i][0] > ret.back()[1]) {
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
