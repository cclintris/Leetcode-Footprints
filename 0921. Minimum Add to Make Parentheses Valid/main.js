/**
 * @param {string} s
 * @return {number}
 */
const minAddToMakeValid = function (s) {
  let stack = [];
  let res = 0;
  for (let c of s) {
    if (c === "(") {
      stack.push(c);
    } else {
      if (stack.length === 0) {
        res++;
      } else {
        stack.pop();
        // console.log(stack)
      }
    }
  }
  //   console.log(res);
  //   console.log(stack.length)
  return res + stack.length;
};

const s = "()";
console.log(minAddToMakeValid(s));
