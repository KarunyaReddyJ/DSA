"use strict";
function suggestedProducts(products, searchWord) {
    products.sort();
    let results = [];
    for (let k = 1; k <= searchWord.length;) {
        let lb = lower_bound(products, searchWord, k);
        let ub = lower_bound(products, searchWord, k, false);
        if (lb === -1) {
            while (k <= searchWord.length) {
                results.push([]);
                k++;
            }
            break;
        }
        let res = [];
        for (let i = lb; i <= ub && i < lb + 3; i++)
            res.push(products[i]);
        results.push(res);
        k++;
    }
    return results;
}
;
function lexographicalOrder(product, searchWord, k) {
    for (let i = 0; i < k; i++) {
        if (product.charCodeAt(i) > searchWord.charCodeAt(i))
            return 1;
        else if (product.charCodeAt(i) < searchWord.charCodeAt(i))
            return -1;
    }
    return 0;
}
function lower_bound(products, searchWord, k, isLower = true) {
    let low = 0, high = products.length - 1;
    let index = -1;
    while (low <= high) {
        let mid = (low + high) >> 1;
        let order = lexographicalOrder(products[mid], searchWord, k);
        if (order === 0) {
            index = mid;
            if (isLower)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else if (order < 0) {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return index;
}
let products = ["havana"];
let searchWord = "havells";
let results = suggestedProducts(products, searchWord);
for (let arr of results)
    console.log(arr);
//# sourceMappingURL=searchSuggestionsSystem.js.map