/**
 * @param {number[][]} vec
 */
let Vector2D = function (vec) {
  this.buffer = [];
  for (let arr of vec) {
    for (let ele of arr) {
      this.buffer.push(ele);
    }
  }
  this.index = 0;
};

/**
 * @return {number}
 */
Vector2D.prototype.next = function () {
  return this.buffer[this.index++];
};

/**
 * @return {boolean}
 */
Vector2D.prototype.hasNext = function () {
  return this.index >= this.buffer.length ? false : true;
};
