
class Queue<T>{
    Q:T[];
    front:number;
    rear:number;
    constructor(){
        this.Q=[]
        this.front=0
        this.rear=-1
    }
    enqueue(el:T):void{
        this.Q.push(el)
        this.rear++
    }
    deque():T{
        if(this.front>this.rear)
            throw new Error('Empty Queue')
        let element=this.Q[this.front]
        this.front++
        return element
    }
    isEmpty():boolean{
        return this.front>this.rear
    }
    peek():T{
        return this.Q[this.front]
    }
}

interface Graph<T>{
    adjList:T[][]
}
const graph:Graph<number>={adjList:[]}

const bfs=(graph:Graph<number>):void=>{
    const queue=new Queue<number>()
    queue.enqueue(0)
    const visited:boolean[]=[]
    for(let i=0;i<graph.adjList.length;i++)
        visited.push(false)
    visited[0]=true
    while(!queue.isEmpty()){
        let elm=queue.deque()
        for(let x of graph.adjList[elm]){
            if(!visited[x]){
                queue.enqueue(x)
                visited[x]=true
            }
        }
        console.log(elm," ")
    }
}
export {}
graph.adjList=[[1,4,5],[0,2],[1,3,5],[2,4],[0,3],[0,1,2]]
bfs(graph)