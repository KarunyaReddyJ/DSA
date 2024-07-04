"use strict";
function numIslands(grid) {
    let islandCount = 0;
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            if (grid[i][j] === '1') {
                islandCount++;
                dfs(grid, i, j);
            }
        }
    }
    return islandCount;
}
;
function dfs(grid, row, col) {
    if (row === grid.length || col === grid[0].length || row === -1 || col === -1 || grid[row][col] === '0')
        return;
    grid[row][col] = '0';
    dfs(grid, row + 1, col);
    dfs(grid, row - 1, col);
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
}
console.log(numIslands([
    ["1", "1", "0", "0", "0"],
    ["1", "1", "0", "0", "0"],
    ["0", "0", "1", "0", "0"],
    ["0", "0", "0", "1", "1"]
]));
//# sourceMappingURL=number_of_islands.js.map