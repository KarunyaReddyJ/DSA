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

function pathSum(root: TreeNode | null, targetSum: number): number[][] {
    const answer: number[][] = [];
    function PathSum(root: TreeNode | null, targetSum: number, sum: number, path: number[]) {
        if (root === null) return;
        sum += root.val;
        path.push(root.val);
        if (root.left === null && root.right === null && sum === targetSum) {
            answer.push([...path]);
        } else {
            PathSum(root.left, targetSum, sum, path);
            PathSum(root.right, targetSum, sum, path);
        }
        path.pop();
    }
    PathSum(root, targetSum, 0, []);
    return answer;
}

// Test case
const root = new TreeNode(5,
    new TreeNode(4,
        new TreeNode(11,
            new TreeNode(7),
            new TreeNode(2)
        ),
        null
    ),
    new TreeNode(8,
        new TreeNode(13),
        new TreeNode(4,
            new TreeNode(5),
            new TreeNode(1)
        )
    )
);

console.log(pathSum(root, 22)); // Expected output: [[5, 4, 11, 2], [5, 8, 4, 5]]
export {}