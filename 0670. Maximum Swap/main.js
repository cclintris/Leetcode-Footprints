const maximumSwap = function (num) {
  const swap = (s, i, j) => {
    let arr = s.split("");
    const c = arr[i];
    arr[i] = arr[j];
    arr[j] = c;
    return arr.join("");
  };

  let numArr = new Array(10).fill(-1);
  let s = num.toString();
  for (let i = 0; i < s.length; i++) {
    // console.log(parseInt(s[i]));
    numArr[parseInt(s[i])] = i;
  }
  for (let i = 0; i < s.length; i++) {
    for (let j = 9; j >= 0; j--) {
      if (numArr[j] != -1 && numArr[j] > i && j > parseInt(s[i])) {
        s = swap(s, i, numArr[j]);
        return new Number(s);
      }
    }
  }
  return num;
};

const num = 9973;
console.log(maximumSwap(num));
