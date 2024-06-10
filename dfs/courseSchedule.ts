function detectCycleInDirectedGraph(numNodes: number, edges: number[][]): boolean {
    const adjList: Map<number, number[]> = new Map();
    for (let [src, dest] of edges) {
        if (!adjList.has(src)) {
            adjList.set(src, []);
        }
        adjList.get(src)!.push(dest);
    }
    const visited: boolean[] = new Array(numNodes).fill(false);
    const recStack: boolean[] = new Array(numNodes).fill(false);
    function dfs(node: number): boolean {
        if (recStack[node]) {
            return true; 
        }
        if (visited[node]) {
            return false; 
        }
        visited[node] = true;
        recStack[node] = true;
        if (adjList.has(node)) {
            for (let neighbor of adjList.get(node)!) {
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


function canFinish(numNodes: number, edges: number[][]):boolean{
    return !detectCycleInDirectedGraph(numNodes,edges,)
}
