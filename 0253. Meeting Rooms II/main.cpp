#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * I: intervals = [[0,30],[5,10],[15,20]]
 * O: 2
 *
 * I: intervals = [[7,10],[2,4]]
 * O: 1
 */

int minMeetingRooms(vector<vector<int>>& intervals);

int main(int argc, char const* argv[]) {
    vector<vector<int>> intervals{{0, 30}, {5, 10}, {15, 20}};
    cout << minMeetingRooms(intervals) << endl;
    return 0;
}

int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int res = 1;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (auto it : intervals) {
        if (minHeap.size() && it[0] < minHeap.top()) {
            res++;
        } else {
            if (minHeap.size())
                minHeap.pop();
        }
        minHeap.push(it[1]);
    }
    return res;
}
