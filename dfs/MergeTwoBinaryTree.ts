class TreeNode {
    val: number;
    left: TreeNode | null;
    right: TreeNode | null;
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val);
        this.left = (left === undefined ? null : left);
        this.right = (right === undefined ? null : right);
    }
}
function getValue(root: TreeNode | null):number{
    if(root===null)
        return 0
    return root.val
}
function mergeTrees(root1: TreeNode | null, root2: TreeNode | null): TreeNode | null {
    return merge(root1,root2)
};
function merge(root1: TreeNode | null, root2: TreeNode | null){
    if(root1===null && root2===null)
        return
    return new TreeNode(getValue(root1)+getValue(root2),merge(root1!==null?root1.left:null,root2!==null?root2.left:null),merge(root1!==null?root1.right:null,root2!==null?root2.right:null))
}
export {}