"use strict";
const adjMatrix = [[1, 1, 1, 0, 0], [1, 0, 1, 0, 0], [0, 0, 0, 1, 0]];
const countIslands = (adjMatrix) => {
    let noOfIslands = 0;
    for (let i = 0; i < adjMatrix.length; i++) {
        for (let j = 0; j < adjMatrix[0].length; j++) {
            if (adjMatrix[i][j]) {
                noOfIslands++;
                dfs(adjMatrix, i, j);
            }
        }
    }
    return noOfIslands;
};
const dfs = (adjMatrix, r, c) => {
    if (r === adjMatrix.length || c === adjMatrix[0].length || r < 0 || c < 0)
        return;
    if (adjMatrix[r][c]) {
        adjMatrix[r][c] = 0;
        dfs(adjMatrix, r + 1, c);
        dfs(adjMatrix, r - 1, c);
        dfs(adjMatrix, r, c + 1);
        dfs(adjMatrix, r, c - 1);
    }
};
console.log(countIslands(adjMatrix));
//# sourceMappingURL=noOfIslands.js.map