"use strict";
function detectCycleInDirectedGraph(numNodes, edges) {
    const adjList = new Map();
    for (let [src, dest] of edges) {
        if (!adjList.has(src)) {
            adjList.set(src, []);
        }
        adjList.get(src).push(dest);
    }
    const visited = new Array(numNodes).fill(false);
    const recStack = new Array(numNodes).fill(false);
    function dfs(node) {
        if (recStack[node]) {
            return true;
        }
        if (visited[node]) {
            return false;
        }
        visited[node] = true;
        recStack[node] = true;
        if (adjList.has(node)) {
            for (let neighbor of adjList.get(node)) {
                if (dfs(neighbor)) {
                    return true;
                }
            }
        }
        recStack[node] = false;
        return false;
    }
    for (let i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                return true;
            }
        }
    }
    return false;
}
function canFinish(numNodes, edges) {
    return !detectCycleInDirectedGraph(numNodes, edges);
}
//# sourceMappingURL=courseSchedule.js.map