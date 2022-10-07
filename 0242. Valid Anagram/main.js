/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
let isAnagram = function (s, t) {
  let len_s = s.length,
    len_t = t.length;
  if (len_s !== len_t) return false;
  const arr_s = new Array(26).fill(0);
  const arr_t = new Array(26).fill(0);
  for (let i = 0; i < len_s; i++) {
    arr_s[s[i].charCodeAt() - 97]++;
    arr_t[t[i].charCodeAt() - 97]++;
  }
  for (let i = 0; i < 26; i++) {
    if (arr_s[i] !== arr_t[i]) return false;
  }
  return true;
};
