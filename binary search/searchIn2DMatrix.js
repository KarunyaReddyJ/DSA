"use strict";
function searchMatrix(matrix, target) {
    for (let row of matrix) {
        if (target < row[0])
            return false;
        if (binarySearch(row, target))
            return true;
    }
    return false;
}
;
function binarySearch(row, target) {
    let low = 0;
    let high = row.length - 1;
    while (low <= high) {
        let mid = (low + high) >> 1;
        if (row[mid] === target)
            return true;
        else if (row[mid] < target) {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return false;
}
//# sourceMappingURL=searchIn2DMatrix.js.map