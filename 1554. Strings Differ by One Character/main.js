/**
 * @param {string[]} dict
 * @return {boolean}
 */
let differByOne = function (dict) {
  let n = dict[0].length;
  let set = new Set();
  for (const str of dict) {
    for (let i = 0; i < n; i++) {
      let mask = str.substring(0, i) + "*" + str.substring(i + 1);
      if (set.has(mask)) return true;
      set.add(mask);
    }
  }
  return false;
};
