/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
const isToeplitzMatrix = function (matrix) {
  let m = matrix.length;
  let n = matrix[0].length;
  let map = new Map();
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (map.has(i - j) && matrix[i][j] != map.get(i - j)) return false;
      map.set(i - j, matrix[i][j]);
    }
  }
  return true;
};
