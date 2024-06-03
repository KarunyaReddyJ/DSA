function singleNumber(nums: number[]): number[] {
    let x = 0;
    for (let n of nums)
        x ^= n;
    
    let firstSetBit = 0;
    for (let i = 0; i < 32; i++) {
        if ((x & (1 << i)) !== 0) {
            firstSetBit = i;
            break;
        }
    }

    let g1 = 0, g2 = 0;
    for (let i of nums) {
        if (isNthBitSet(i, firstSetBit))
            g1 ^= i;
        else
            g2 ^= i;
    }

    return [g1, g2];
}

function isNthBitSet(num: number, n: number): boolean {
    return (num & (1 << n)) !== 0;
}

console.log(singleNumber([1, 2, 1, 3, 2, 5])); // Output: [3, 5]
