"use strict";
function hammingWeight(n) {
    let str = '';
    while (n) {
        str += String.fromCharCode('0'.charCodeAt(0) + (n % 2));
        n = n >> 1;
    }
    return count(str, 0, 0, str.length - 1);
}
function count(str, cnt, low, high) {
    if (low === high)
        return str[low] === '1' ? 1 : 0;
    let mid = (low + high) >> 1;
    return count(str, cnt, low, mid) + count(str, cnt, mid + 1, high);
}
//# sourceMappingURL=noOf1Bits.js.map