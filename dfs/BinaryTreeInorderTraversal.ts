

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
 
function inorderTraversal(root: TreeNode | null): number[] {
    let traversal:number[]=[]
    inorder(root,traversal)
    return traversal
};
function inorder(root:TreeNode|null,traversal:number[]){
    if(root===null)
        return
    inorder(root.left,traversal)
    traversal.push(root.val)
    inorder(root.right,traversal)
}
const root=new TreeNode(1)
root.right=new TreeNode(2)
root.right.left=new TreeNode(3)
console.log(inorderTraversal(root))