#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * I: nums = [10,2]
 * O: "210"
 *
 * I: nums = [3,30,34,5,9]
 * O: "9534330"
 */

string largestNumber(vector<int>& nums);

bool static cmp(string s1, string s2);
int main(int argc, char const* argv[]) {
    vector<int> nums{10, 2, 9, 39, 17};
    cout << largestNumber(nums) << endl;
    return 0;
}

string largestNumber(vector<int>& nums) {
    string res = "";
    int n = nums.size();
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = to_string(nums[i]);
    }
    sort(arr.begin(), arr.end(), cmp);
    if (arr[0] == "0") return "0";
    for (int i = 0; i < n; i++) res += arr[i];
    return res;
}

bool static cmp(string s1, string s2) {
    string cmp1 = s1 + s2;
    string cmp2 = s2 + s1;
    return cmp1 > cmp2;
}
