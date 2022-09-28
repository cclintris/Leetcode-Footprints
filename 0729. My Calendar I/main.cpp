#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

// linear time complexity
class MyCalendar {
   public:
    MyCalendar() {
    }

    bool book(int start, int end) {
        for (auto cal : calender) {
            if (start >= cal.first && start < cal.second) return false;
            if (start <= cal.first && end > cal.first) return false;
        }
        calender.push_back({start, end});
        return true;
    }

   private:
    vector<pair<int, int>> calender;
};

// O(logn) time complexity with binary search + sorted list
class MyCalendar {
   public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto it = cal.lower_bound(start);
        if (it != cal.end() && it->first < end) return false;
        if (it != cal.begin() && prev(it)->second > start) return false;
        cal[start] = end;
        return true;
    }

   private:
    map<int, int> cal;
};

int main(int argc, char const *argv[]) {
    return 0;
}
