function singleNumber(nums) {
    var x = 0;
    for (var _i = 0, nums_1 = nums; _i < nums_1.length; _i++) {
        var n = nums_1[_i];
        x ^= n;
    }
    var firstSetBit = 0;
    for (var i = 0; i < 32; i++) {
        if ((x & (1 << i)) !== 0) {
            firstSetBit = i;
            break;
        }
    }
    var g1 = 0, g2 = 0;
    for (var _a = 0, nums_2 = nums; _a < nums_2.length; _a++) {
        var i = nums_2[_a];
        if (isNthBitSet(i, firstSetBit))
            g1 ^= i;
        else
            g2 ^= i;
    }
    return [g1, g2];
}
function isNthBitSet(num, n) {
    return (num & (1 << n)) !== 0;
}
console.log(singleNumber([1, 2, 1, 3, 2, 5])); // Output: [3, 5]
