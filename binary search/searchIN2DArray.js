"use strict";
;
function binarySearch(matrix, target) {
    let low = { x: 0, y: 0 }, high = { x: matrix.length - 1, y: matrix[0].length - 1 }, size = { x: matrix.length, y: matrix[0].length };
    while (unWrap(low, size) <= unWrap(high, size)) {
        let mid = wrap((unWrap(low, size) + unWrap(high, size)) >> 1, size);
        if (matrix[mid.x][mid.y] === target)
            return true;
        else if (matrix[mid.x][mid.y] < target)
            low = wrap(unWrap(mid, size), size, 1);
        else
            high = wrap(unWrap(mid, size), size, -1);
    }
    return false;
}
function unWrap(p, size) {
    return p.x * size.y + p.y;
}
function wrap(l, size, oper = 0) {
    let p = {
        x: Math.floor((l + oper) / size.x),
        y: (l + oper) % size.x
    };
    return p;
}
console.log(binarySearch([[1, 2, 3, 4], [5, 6, 7, 8]], 12));
//# sourceMappingURL=searchIN2DArray.js.map