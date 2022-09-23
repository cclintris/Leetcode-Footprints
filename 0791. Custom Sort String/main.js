/**
 * @param {string} order
 * @param {string} s
 * @return {string}
 */
const customSortString = function (order, s) {
  let map = new Map();
  for (let i = 0; i < s.length; i++) {
    if (map.has(s[i])) {
      map.set(s[i], map.get(s[i]) + 1);
    } else {
      map.set(s[i], 1);
    }
  }
  let res = "";
  for (let i = 0; i < order.length; i++) {
    if (map.has(order[i])) {
      while (map.get(order[i]) > 0) {
        res += order[i];
        map.set(order[i], map.get(order[i]) - 1);
      }
    }
  }
  for (let [k, v] of map) {
    if (v > 0) {
      while (v > 0) {
        res += k;
        v--;
      }
    }
  }
  return res;
};
