#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<pair<int, bool>> dp;

public:
    Solution() : dp(1e3, {-1, false}) {}
    bool isPrims(int n)
    {
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
    set<int> factors(int x)
    {
        set<int> fact;
        fact.insert(1);
        if (isPrims(x))
            return fact;
        while (x && !isPrims(x))
        {
            for (int i = 2; i < x; i++)
            {
                if (x % i == 0)
                {
                    x /= i;
                    fact.insert(i);
                    break;
                }
            }
        }
        fact.insert(x);
        return fact;
    }
    bool divisorGame(int n, bool bob = false)
    {
        if (n == 1)
            return bob;
        if (dp[n].first != -1)
        {
            
        }
        set<int> fctrs = factors(n);
        for (int i : fctrs)
        {
            if ((n & 1 || ((n - i) & 1)) && divisorGame(n - i, !bob))
                return true;
        }
        return false;
    }
};
int main()
{
    Solution s;
    int n;
    cin >> n;
    cout << s.divisorGame(n);
}