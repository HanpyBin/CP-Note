class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        int res = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[startRow][startColumn] = 1;
        int mod = 1000000007;
        while (maxMove--)
        {
            vector<vector<int>> t(m, vector<int>(n));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                {
                    int a = i > 0 ? dp[i-1][j] : 0;
                    int b = j > 0 ? dp[i][j-1] : 0;
                    int c = i < m-1 ? dp[i+1][j] : 0;
                    int d = j < n-1 ? dp[i][j+1] : 0;
                    t[i][j] = (t[i][j] + a % mod) % mod;
                    t[i][j] = (t[i][j] + b % mod) % mod;
                    t[i][j] = (t[i][j] + c % mod) % mod;
                    t[i][j] = (t[i][j] + d % mod) % mod;
                    if (!i)
                        res = (res + dp[i][j] % mod) % mod;
                    if (!j)
                        res = (res + dp[i][j] % mod) % mod;
                    if (i == m-1)
                        res = (res + dp[i][j] % mod) % mod;
                    if (j == n-1)
                        res = (res + dp[i][j] % mod) % mod;
                }
            dp = t;
        }
        return res;
    }
};