#include <iostream>
#include <vector>
using namespace std;

/**
 * I: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
 * O: 3
 * Explanation:
    Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
    Travel to station 4. Your tank = 4 - 1 + 5 = 8
    Travel to station 0. Your tank = 8 - 2 + 1 = 7
    Travel to station 1. Your tank = 7 - 3 + 2 = 6
    Travel to station 2. Your tank = 6 - 4 + 3 = 5
    Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
    Therefore, return 3 as the starting index.
 *
 * I: gas = [2,3,4], cost = [3,4,3]
 * O: -1
 * Explanation:
    You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
    Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
    Travel to station 0. Your tank = 4 - 3 + 2 = 3
    Travel to station 1. Your tank = 3 - 3 + 3 = 3
    You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
    Therefore, you can't travel around the circuit once no matter where you start.
 */

int canCompleteCircuit(vector<int>& gas, vector<int>& cost);

int main(int argc, char const* argv[]) {
    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};
    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sumGas = 0, sumCost = 0;
    int n = gas.size();
    for (int i = 0; i < n; i++) {
        sumGas += gas[i];
        sumCost += cost[i];
    }
    if (sumGas < sumCost)
        return -1;

    int tank = 0;
    int res = 0;
    // vector<int> diff(n, 0);
    // for (int i = 0; i < n; i++) {
    //     diff[i] = gas[i] - cost[i];
    // }
    for (int i = 0; i < n - 1; i++) {
        tank += gas[i] - cost[i];
        if (tank < 0) {
            tank = 0;
            res = i + 1;
        }
    }
    return res;
}
