function suggestedProducts(products, searchWord) {
    products.sort();
    var results = [];
    for (var k = 1; k <= searchWord.length;) {
        var lb = lower_bound(products, searchWord, k);
        var ub = lower_bound(products, searchWord, k, false);
        if (lb === -1) {
            while (k <= searchWord.length) {
                results.push([]);
                k++;
            }
            break;
        }
        var res = [];
        for (var i = lb; i <= ub && i < lb + 3; i++)
            res.push(products[i]);
        results.push(res);
        k++;
    }
    return results;
}
;
function lexographicalOrder(product, searchWord, k) {
    for (var i = 0; i < k; i++) {
        if (product.charCodeAt(i) > searchWord.charCodeAt(i))
            return 1;
        else if (product.charCodeAt(i) < searchWord.charCodeAt(i))
            return -1;
    }
    return 0;
}
function lower_bound(products, searchWord, k, isLower) {
    if (isLower === void 0) { isLower = true; }
    var low = 0, high = products.length - 1;
    var index = -1;
    while (low <= high) {
        var mid = (low + high) >> 1;
        var order = lexographicalOrder(products[mid], searchWord, k);
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
var products = ["havana"];
var searchWord = "havells";
var results = suggestedProducts(products, searchWord);
for (var _i = 0, results_1 = results; _i < results_1.length; _i++) {
    var arr = results_1[_i];
    console.log(arr);
}
