function TreeNode(val) {
  this.val = val;
  this.left = this.right = null;
}

let lowestCommonAncestor = function (root, p, q) {
  if (root === null) return null;
  if (root.val == p.val || root.val == q.val) return root;
  const left = lowestCommonAncestor(root.left, p, q);
  const right = lowestCommonAncestor(root.right, p, q);
  if (left && right) return root;
  return left ? left : right;
};
