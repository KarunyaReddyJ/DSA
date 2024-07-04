"use strict";
function longestPalindrome(s) {
    const hash = {};
    for (let char of s) {
        if (!hash[char]) {
            hash[char] = 0;
        }
        hash[char]++;
    }
    let length = 0;
    let hasOdd = false;
    for (let key in hash) {
        if (hash[key] % 2 === 0) {
            length += hash[key];
        }
        else {
            length += hash[key] - 1;
            hasOdd = true;
        }
    }
    if (hasOdd) {
        length += 1;
    }
    return length;
}
console.log(longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth")); // Output: 983
//# sourceMappingURL=longest_palindorme.js.map