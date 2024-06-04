function longestPalindrome(s) {
    var hash = {};
    // Populate the hash with character counts
    for (var _i = 0, s_1 = s; _i < s_1.length; _i++) {
        var char = s_1[_i];
        if (!hash[char]) {
            hash[char] = 0;
        }
        hash[char]++;
    }
    for (var key in hash) {
        console.log(key, ":", hash[key], "\n");
    }
    var length = 0;
    var hasOdd = false;
    // Calculate the maximum length of the palindrome
    for (var key in hash) {
        if (hash[key] % 2 === 0) {
            length += hash[key];
        }
        else {
            length += hash[key] - 1;
            hasOdd = true;
        }
    }
    // Add one if there is at least one odd count character
    if (hasOdd) {
        length += 1;
    }
    return length;
}
console.log(longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth")); // Output: 983
