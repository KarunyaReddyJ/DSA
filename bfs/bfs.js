"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class Queue {
    constructor() {
        this.Q = [];
        this.front = 0;
        this.rear = -1;
    }
    enqueue(el) {
        this.Q.push(el);
        this.rear++;
    }
    deque() {
        if (this.front > this.rear)
            throw new Error('Empty Queue');
        let element = this.Q[this.front];
        this.front++;
        return element;
    }
    isEmpty() {
        return this.front > this.rear;
    }
    peek() {
        return this.Q[this.front];
    }
}
const graph = { adjList: [] };
const bfs = (graph) => {
    const queue = new Queue();
    queue.enqueue(0);
    const visited = [];
    for (let i = 0; i < graph.adjList.length; i++)
        visited.push(false);
    visited[0] = true;
    while (!queue.isEmpty()) {
        let elm = queue.deque();
        for (let x of graph.adjList[elm]) {
            if (!visited[x]) {
                queue.enqueue(x);
                visited[x] = true;
            }
        }
        console.log(elm, " ");
    }
};
graph.adjList = [[1, 4, 5], [0, 2], [1, 3, 5], [2, 4], [0, 3], [0, 1, 2]];
bfs(graph);
//# sourceMappingURL=bfs.js.map