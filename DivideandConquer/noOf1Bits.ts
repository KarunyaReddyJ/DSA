function hammingWeight(n: number): number {
    let str:string=''
    while(n){
        str+=String.fromCharCode('0'.charCodeAt(0)+(n%2))
        n=n>>1
    }
    return count(str,0,0,str.length-1)
}
function count(str:string,cnt:number,low:number,high:number):number{
    if(low===high)
        return str[low]==='1'?1:0
    let mid=(low+high)>>1
    return count(str,cnt,low,mid)+count(str,cnt,mid+1,high)
}