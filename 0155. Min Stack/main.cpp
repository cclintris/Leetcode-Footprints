#include <iostream>
#include <stack>
using namespace std;

/**
 * I: ["MinStack","push","push","push","getMin","pop","top","getMin"]
    [[],[-2],[0],[-3],[],[],[],[]]
 * O: [null,null,null,null,-3,null,0,-2]
 *
 *
 * Explanation
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
 */

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
   public:
    MinStack() {
    }

    void push(int val) {
        if (ss.empty() || val <= ss.top()) {
            ss.push(val);
        }
        s.push(val);
    }

    void pop() {
        if (s.top() == ss.top())
            ss.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return ss.top();
    }

   private:
    stack<int> s;
    stack<int> ss;
};

int main(int argc, char const *argv[]) {
    return 0;
}
