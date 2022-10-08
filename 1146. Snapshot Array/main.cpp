#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

// Input: ["SnapshotArray","set","snap","set","get"]
// [[3],[0,5],[],[0,6],[0,0]]
// Output: [null,null,0,null,5]
// Explanation:
// SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
// snapshotArr.set(0,5);  // Set array[0] = 5
// snapshotArr.snap();  // Take a snapshot, return snap_id = 0
// snapshotArr.set(0,6);
// snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5

// MLE
// class SnapshotArray {
//    public:
//     SnapshotArray(int length) {
//         arr.resize(length);
//         cnt = 0;
//         snapID = cnt - 1;
//     }

//     void set(int index, int val) {
//         arr[index] = val;
//     }

//     int snap() {
//         cnt++;
//         snapID = cnt - 1;
//         mp[snapID] = arr;
//         return snapID;
//     }

//     int get(int index, int snap_id) {
//         return mp[snap_id][index];
//     }

//    private:
//     vector<int> arr;
//     unordered_map<int, vector<int>> mp;
//     int cnt;
//     int snapID;
// };

class SnapshotArray {
   public:
    SnapshotArray(int length) {
        snapID = 0;
    }

    void set(int index, int val) {
        mp[snapID][index] = val;
    }

    int snap() {
        snapID++;
        mp[snapID] = mp[snapID - 1];
        return snapID - 1;
    }

    int get(int index, int snap_id) {
        return mp[snap_id][index];
    }

   private:
    unordered_map<int, map<int, int>> mp;
    int snapID;
};

int main(int argc, char const *argv[]) {
    return 0;
}
