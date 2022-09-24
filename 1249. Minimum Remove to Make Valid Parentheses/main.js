/**
 * @param {string} s
 * @return {string}
 */
const minRemoveToMakeValid = function (s) {
  const stack = [];
  const splitArr = s.split("");
  //   console.log(splitArr);
  for (let i = 0; i < s.length; i++) {
    if (s[i] === "(") {
      stack.push(i);
    } else if (s[i] === ")") {
      if (stack.length === 0) {
        splitArr[i] = "";
      } else {
        stack.pop();
      }
    }
  }
  //   console.log(splitArr);
  for (let i = 0; i < stack.length; i++) {
    splitArr[stack[i]] = "";
  }
  return splitArr.join("");
};

const s = "lee(t(c)o)de)";
console.log(minRemoveToMakeValid(s));
