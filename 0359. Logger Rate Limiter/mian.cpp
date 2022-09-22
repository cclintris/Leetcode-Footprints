#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * Input
    ["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
    [[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
   Output
    [null, true, true, false, false, false, true]

    Explanation
    Logger logger = new Logger();
    logger.shouldPrintMessage(1, "foo");  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
    logger.shouldPrintMessage(2, "bar");  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
    logger.shouldPrintMessage(3, "foo");  // 3 < 11, return false
    logger.shouldPrintMessage(8, "bar");  // 8 < 12, return false
    logger.shouldPrintMessage(10, "foo"); // 10 < 11, return false
    logger.shouldPrintMessage(11, "foo"); // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21
 */

class Logger {
   public:
    Logger() {
    }

    bool shouldPrintMessage(int timestamp, string message) {
        if (mp.find(message) == mp.end()) {
            mp[message] = timestamp;
            return true;
        } else {
            if (timestamp >= mp[message] + 10) {
                mp[message] = timestamp;
                return true;
            }
        }
        return false;
    }

   private:
    unordered_map<string, int> mp;
};

int main(int argc, char const *argv[]) {
    return 0;
}
