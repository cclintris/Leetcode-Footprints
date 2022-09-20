#include <deque>
#include <iostream>
using namespace std;

/**
 * I: ["MovingAverage", "next", "next", "next", "next"]
      [[3], [1], [10], [3], [5]]
 * O: [null, 1.0, 5.5, 4.66667, 6.0]

    Explanation
    MovingAverage movingAverage = new MovingAverage(3);
    movingAverage.next(1); // return 1.0 = 1 / 1
    movingAverage.next(10); // return 5.5 = (1 + 10) / 2
    movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
    movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
 */

class MovingAverage {
   public:
    MovingAverage(int size) {
        window = size;
    }

    double next(int val) {
        double tmp = 0;
        if (dq.size() >= window) {
            dq.pop_back();
        }
        dq.push_front(val);
        for (int i = dq.size() - 1; i >= 0; i--) {
            tmp += dq[i];
        }
        return tmp / dq.size();
    }

   private:
    deque<int> dq;
    int window;
};

int main(int argc, char const *argv[]) {
    return 0;
}
