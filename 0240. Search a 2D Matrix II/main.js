/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
let searchMatrix = function (matrix, target) {
  let row = matrix.length;
  let col = matrix[0].length;
  let r = 0;
  let c = col - 1;
  while (r >= 0 && r < row && c >= 0 && c < col) {
    if (matrix[r][c] == target) return true;
    if (matrix[r][c] > target) {
      c--;
    } else {
      r++;
    }
  }
  return false;
};
