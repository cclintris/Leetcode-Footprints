#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nestedList = [[1,1],2,[1,1]]
 * O: 10
 * Explanation: Four 1's at depth 2, one 2 at depth 1. 1*2 + 1*2 + 2*1 + 1*2 + 1*2 = 10
 *
 * I: nestedList = [0]
 * O: 0
 */

class NestedInteger {
   public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger& ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const;
};

int depthSum(vector<NestedInteger>& nestedList);

void dfs(NestedInteger& nestedInt, int& res, int depth);

int main(int argc, char const* argv[]) {
    return 0;
}

int depthSum(vector<NestedInteger>& nestedList) {
    int n = nestedList.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        dfs(nestedList[i], res, 1);
    }
    return res;
}

void dfs(NestedInteger& nestedInt, int& res, int depth) {
    if (nestedInt.isInteger()) {
        res += nestedInt.getInteger() * depth;
        return;
    } else {
        vector<NestedInteger> ni = nestedInt.getList();
        for (int i = 0; i < ni.size(); i++) {
            dfs(ni[i], res, depth + 1);
        }
    }
}
