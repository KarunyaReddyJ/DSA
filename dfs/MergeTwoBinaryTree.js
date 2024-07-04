"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class TreeNode {
    constructor(val, left, right) {
        this.val = (val === undefined ? 0 : val);
        this.left = (left === undefined ? null : left);
        this.right = (right === undefined ? null : right);
    }
}
function getValue(root) {
    if (root === null)
        return 0;
    return root.val;
}
function mergeTrees(root1, root2) {
    return merge(root1, root2);
}
;
function merge(root1, root2) {
    if (root1 === null && root2 === null)
        return;
    return new TreeNode(getValue(root1) + getValue(root2), merge(root1 !== null ? root1.left : null, root2 !== null ? root2.left : null), merge(root1 !== null ? root1.right : null, root2 !== null ? root2.right : null));
}
//# sourceMappingURL=MergeTwoBinaryTree.js.map