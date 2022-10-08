/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
let shortestPath = function (grid, k) {
  let m = grid.length,
    n = grid[0].length;
  let obstacles = new Array(m).fill(0).map(() => new Array(n).fill(-1));
  let queue = [];
  let dir = [
    [0, 1],
    [0, -1],
    [1, 0],
    [-1, 0],
  ];
  let step = 0;
  queue.push([0, 0, k]);
  obstacles[0][0] = k;
  while (queue.length) {
    let size = queue.length;
    let moves = [];
    while (size) {
      let front = queue.pop();
      if (front[0] == m - 1 && front[1] == n - 1) return step;
      for (const d of dir) {
        let new_x = front[0] + d[0];
        let new_y = front[1] + d[1];
        if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) continue;
        let new_k = front[2] - grid[new_x][new_y];
        if (new_k <= obstacles[new_x][new_y]) continue;
        obstacles[new_x][new_y] = new_k;
        moves.push([new_x, new_y, new_k]);
      }
      size--;
    }
    queue = moves;
    step++;
  }
  return -1;
};
