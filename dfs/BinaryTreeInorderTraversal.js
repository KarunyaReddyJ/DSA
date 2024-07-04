"use strict";
class TreeNode {
    constructor(val, left, right) {
        this.val = (val === undefined ? 0 : val);
        this.left = (left === undefined ? null : left);
        this.right = (right === undefined ? null : right);
    }
}
function inorderTraversal(root) {
    let traversal = [];
    inorder(root, traversal);
    return traversal;
}
;
function inorder(root, traversal) {
    if (root === null)
        return;
    inorder(root.left, traversal);
    traversal.push(root.val);
    inorder(root.right, traversal);
}
const root = new TreeNode(1);
root.right = new TreeNode(2);
root.right.left = new TreeNode(3);
console.log(inorderTraversal(root));
//# sourceMappingURL=BinaryTreeInorderTraversal.js.map