class CustomFunction {
         f(x: number, y: number): number {}
     }
function findSolution(customfunction: CustomFunction, z: number): number[][] {
    const result:number[][]=[]
	for(let i=1;i<=z;i++){
        let ind=binarySearch(customfunction,i,z)
            if(ind!==-1)
                result.push([i,ind])
    }
    return result
};
function binarySearch(customfunction: CustomFunction,row:number,z:number):number{
    let low=1,high=z
    while(low<=high){
        let mid=(high+low)>>1
        if(customfunction(row,mid)===z)
            return mid
        else if(customfunction(row,mid)<z)
            low=mid+1
        else
            high=mid-1
    }
    return -1
}
export {}