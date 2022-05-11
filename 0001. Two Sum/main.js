let nums = [3, 3],
  target = 6;

/**
 * [3,2,3]
 * [2,3,3]
 * [0,1,2]
 */

const twoSum = function (nums, target) {
  const arr = [...nums].sort((a, b) => a - b);
  let res = [];
  let left = 0,
    right = arr.length - 1;

  while (left !== right) {
    let cur = arr[left] + arr[right];
    if (cur === target) {
      break;
    }
    if (cur > target) {
      right--;
    } else {
      left++;
    }
  }

  left = nums.indexOf(arr[left]);
  right = nums.lastIndexOf(arr[right]);

  res.push(left, right);

  return res;
};

console.log(twoSum(nums, target));
