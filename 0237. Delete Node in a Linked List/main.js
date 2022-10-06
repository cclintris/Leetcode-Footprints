function ListNode(val) {
  this.val = val;
  this.next = null;
}

let deleteNode = function (node) {
  let next = node.next;
  if (next.next) {
    let target = next.next;
    node.val = next.val;
    node.next = target;
  } else {
    node.val = next.val;
    node.next = null;
  }
};
