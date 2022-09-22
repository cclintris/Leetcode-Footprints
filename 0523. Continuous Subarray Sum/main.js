/**
 *  Input: nums = [23,2,4,6,7], k = 6
    Output: true
    Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

    Input: nums = [23,2,6,4,7], k = 6
    Output: true
    Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
    42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.

    Input: nums = [23,2,6,4,7], k = 13
    Output: false
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
const checkSubarraySum = function (nums, k) {
  const map = new Map([[0, -1]]);
  let sum = 0;
  for (let i = 0; i < nums.length; i++) {
    sum += nums[i];
    const r = sum % k;
    if (map.has(r)) {
      if (i - map.get(r) > 1) return true;
    } else {
      map.set(r, i);
    }
  }
  return false;
};

const nums = [23, 2, 4, 6, 6];
const k = 7;
console.log(checkSubarraySum(nums, k));
