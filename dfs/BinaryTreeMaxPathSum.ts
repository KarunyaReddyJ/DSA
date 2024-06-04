class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.left = (left===undefined ? null : left)
        this.right = (right===undefined ? null : right)
     }
 }
 function max(n1:number,n2:number):number{
    return n1>n2?n1:n2
 }
 function maxPathSum(root: TreeNode | null): number {
    return 0
 };
 function recursivePathSum(root:TreeNode|null):number{
    if(root===null)
        return 0
    return root.val+max(recursivePathSum(root.left),recursivePathSum(root.right))
 }