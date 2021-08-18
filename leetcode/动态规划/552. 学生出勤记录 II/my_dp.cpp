class Solution
{
public:
    int checkRecord(int n)
    {
        if (n == 1)
            return 3;
        long long mod = 1e9 + 7;
        vector<long long> dl(n+1), dp(n+1), d(n+1);
        dl[0] = 0;
        dp[0] = dp[1] = dl[1] = 1;
        d[0] = 1;
        d[1] = 2;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = (dp[i-1] + dl[i-1]) % mod;
            dl[i] = (dp[i-2] + dp[i-1]) % mod;
            d[i] = (dp[i] + dl[i]) % mod;
        }
        int res = 0;
        for (int i = 1; i <= n/2; i++)
            res = (res + (d[i-1] * d[n-i]) % mod) % mod;
        res = (res * 2) % mod;
        if (n & 1)
            res = (res + (d[n/2] * d[n/2]) % mod) % mod;
        res = (res + d[n]) % mod;
        return res;
    }
};