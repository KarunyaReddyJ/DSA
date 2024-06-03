export interface Graph<T>{
    [key:string]:T[]
}
export interface GraphVisit {
    [key:string]:boolean
}
const adjList:Graph<string>={
    'A':['B','C'],
    'B':['A','D','E'],
    'C':['A','E'],
    'D':['B','E','F'],
    'F':['D','E'],
    'E':['B','C','D']
}
const visited:GraphVisit={}
for(let key in adjList)
    visited[key]=false
const dfs=(adjList:Graph<string>,start:string,visited:GraphVisit):void=>{
    visited[start]=true
    console.log(start)
    for( let path of adjList[start])
        if(!visited[path])
            dfs(adjList,path,visited)
}
export default dfs
dfs(adjList,'E',visited)