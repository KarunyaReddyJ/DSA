function canFinish(numCourses: number, prerequisites: number[][]): boolean {
    const adjList:number[][]=[]
    for(let i=0;i<numCourses;i++){
        adjList.push([]);
    }
    for(let [c,p] of prerequisites){
        adjList[c].push(p)
    }
    for(let [c,p] of prerequisites){
        let visited:boolean[]=[]
        for(let i=0;i<numCourses;i++){
            visited.push(false);
        }
        if(isCycle(adjList,p,c,visited))
            return false
    }
    return true
};
function isCycle(adjList:number[][],start:number,target:number,visited:boolean[]){
    if(start===target)
        return true
    let ans=false
    for(let x of adjList[start]){
        ans=ans || isCycle(adjList,x,target,visited)
    }
    return ans
}
console.log(canFinish(3,[[1,0],[2,0],[0,2]]))