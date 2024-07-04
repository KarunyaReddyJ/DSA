"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class TreeNode {
    constructor(val, left, right) {
        this.val = (val === undefined ? 0 : val);
        this.left = (left === undefined ? null : left);
        this.right = (right === undefined ? null : right);
    }
}
function isSymmetric(root) {
    if (root === null)
        return true;
    return check(root, root);
}
;
function check(root1, root2) {
    if (root1 === null && root2 === null)
        return true;
    else if ((root1 === null && root2 !== null) || (root1 !== null && root2 === null) || root1.val !== root2.val)
        return false;
    return (check(root1.left, root2.right) && check(root1.right, root2.left));
}
//# sourceMappingURL=isSymmetric.js.map