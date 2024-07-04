"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const adjList = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'E'],
    'D': ['B', 'E', 'F'],
    'F': ['D', 'E'],
    'E': ['B', 'C', 'D']
};
const visited = {};
for (let key in adjList)
    visited[key] = false;
const dfs = (adjList, start, visited) => {
    visited[start] = true;
    console.log(start);
    for (let path of adjList[start])
        if (!visited[path])
            dfs(adjList, path, visited);
};
exports.default = dfs;
dfs(adjList, 'E', visited);
//# sourceMappingURL=dfs.js.map