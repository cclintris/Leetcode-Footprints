/**
 * @param {string} s
 * @return {number}
 */
let calculate = function (s) {
  let len = s.length;
  if (len === 0) return 0;
  let stack = [];
  let operator = "+";
  let currentNumber = 0;
  for (let i = 0; i < len; i++) {
    let curChar = s[i];
    // console.log(curChar);
    if (curChar >= "0" && curChar <= "9") {
      currentNumber = currentNumber * 10 + Number(curChar);
    }
    if (
      (!(curChar >= "0" && curChar <= "9") && curChar !== " ") ||
      i === len - 1
    ) {
      let top;
      switch (operator) {
        case "+":
          stack.push(currentNumber);
          //   console.log(stack);
          break;
        case "-":
          stack.push(-currentNumber);
          //   console.log(stack);
          break;
        case "*":
          top = stack.pop();
          stack.push(top * currentNumber);
          //   console.log(stack);
          break;
        case "/":
          top = stack.pop();
          stack.push(parseInt(top / currentNumber));
          //   console.log(stack);
          break;

        default:
          break;
      }
      currentNumber = 0;
      operator = curChar;
    }
  }
  console.log(stack);
  return stack.reduce((a, b) => {
    return a + b;
  });
};

const s = "3/2";
console.log(calculate(s));
