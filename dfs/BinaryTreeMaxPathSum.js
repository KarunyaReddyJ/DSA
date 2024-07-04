"use strict";
class TreeNode {
    constructor(val, left, right) {
        this.val = (val === undefined ? 0 : val);
        this.left = (left === undefined ? null : left);
        this.right = (right === undefined ? null : right);
    }
}
function max(n1, n2) {
    return n1 > n2 ? n1 : n2;
}
function maxPathSum(root) {
    return 0;
}
;
function recursivePathSum(root) {
    if (root === null)
        return 0;
    return root.val + max(recursivePathSum(root.left), recursivePathSum(root.right));
}
//# sourceMappingURL=BinaryTreeMaxPathSum.js.map