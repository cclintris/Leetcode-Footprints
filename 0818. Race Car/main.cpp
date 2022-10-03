#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
using namespace std;

/**
 * I: target = 3
 * O: 2
 *
 * I: target = 6
 * O: 5
 */

int racecar(int target);

int main(int argc, char const *argv[]) {
    int target = 3;
    cout << racecar(target) << endl;
    return 0;
}

// BFS
int racecar(int target) {
    int res = 0;
    queue<pair<int, int>> q;
    q.push({0, 1});
    unordered_set<string> set;
    set.insert("0,1");
    while (!q.empty()) {
        for (int i = q.size(); i > 0; i--) {
            pair<int, int> front = q.front();
            q.pop();
            int pos = front.first;
            int speed = front.second;
            if (pos == target) return res;
            // A instruction
            int newPos = pos + speed;
            int newSpeed = speed * 2;
            string key = to_string(newPos) + "," + to_string(newSpeed);
            if (!set.count(key) && newPos > 0 && newPos < target * 2) {
                q.push({newPos, newSpeed});
                set.insert(key);
            }
            // R instruction
            newPos = pos;
            newSpeed = speed > 0 ? -1 : 1;
            key = to_string(newPos) + "," + to_string(newSpeed);
            if (!set.count(key) && newPos > 0 && newPos < target * 2) {
                q.push({newPos, newSpeed});
                set.insert(key);
            }
        }
        res++;
    }
    return res;
}
