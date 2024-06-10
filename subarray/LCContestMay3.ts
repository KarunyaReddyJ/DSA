
function countDistinct(nums: number[], k: number, p: number): number {
    let count=0
    const set=new Set<number[]>()
    for(let i=0;i<nums.length;i++){
        let divisors=0
        let subArray:number[]=[]
        for(let j=i;j<nums.length;j++){
            if(nums[j]%p===0){
                if(divisors<k){
                    divisors++;
                    set.add(subArray)
                }
                else
                    break;
            }
            subArray.push(nums[j])
        }
    }
    return set.size()
};

console.log(countDistinct([2,3,3,2,2],2,2))