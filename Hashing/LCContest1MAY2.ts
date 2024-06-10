interface set {
    [key:number]:number
}
function minimumCardPickup(cards: number[]): number {
    let minLength=1e6
    let set:set={}
    for(let i=0;i<cards.length;i++){
        if(set[cards[i]]===undefined)
            set[cards[i]]=i
        else{   
            minLength=Math.min(minLength,i+1-set[cards[i]])
            set[cards[i]]=i
        }
    }
    return minLength!==1e6?minLength:-1
};
console.log(minimumCardPickup([0,0]))
export {}