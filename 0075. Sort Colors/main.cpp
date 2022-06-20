#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [2,0,2,1,1,0]
 * O: [0,0,1,1,2,2]
 *
 * I: nums = [2,0,1]
 * O: [0,1,2]
 */

void sortColors(vector<int>& nums);

void printV(vector<int> vec);

int main(int argc, char const* argv[]) {
    int n = 1;
    int arr[1] = {2};
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        nums[i] = arr[i];
    sortColors(nums);
    printV(nums);
    return 0;
}

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int red = 0, white = 0, blue = 0;
    for (int i = 0; i < n; i++) {
        switch (nums[i]) {
            case 0:
                red++;
                break;
            case 1:
                white++;
                break;
            case 2:
                blue++;
                break;
            default:
                cout << "No color" << endl;
                break;
        }
    }

    int ptr = 0;
    for (int i = ptr; i < red; i++)
        nums[i] = 0;
    ptr += red;
    for (int i = ptr; i < ptr + white; i++)
        nums[i] = 1;
    ptr += white;
    for (int i = ptr; i < ptr + blue; i++)
        nums[i] = 2;
}

void printV(vector<int> vec) {
    int l = vec.size();
    cout << "[";
    for (int i = 0; i < l; i++) {
        if (i == l - 1)
            cout << vec[i];
        else
            cout << vec[i] << ",";
    }
    cout << "]" << endl;
}
