
function partition(arr:number[],low:number,high:number):number[]{
    if(low<high){
       let  mid=(low+high)>>1
       partition(arr,low,mid)
       partition(arr,mid+1,high)
       return merge(arr,low,mid,high)
    }
    else return []
}
function merge(arr:number[],low:number,mid:number,high:number):number[]{
    let tempArr:number[]=[]
    let l=low,r=mid+1
    while(l<=mid && r<=high ){
        if(arr[l]<=arr[r])
            tempArr.push(arr[l++])
        else
            tempArr.push(arr[r++])
    }
    while(l<=mid)
        tempArr.push(arr[l++])
    while(r<=high)
        tempArr.push(arr[r++])
    for (let i = low; i <= high; i++) {
        arr[i] = tempArr[i - low];
    }

    return arr;
}

console.log(partition([4,3,1,2],0,3))