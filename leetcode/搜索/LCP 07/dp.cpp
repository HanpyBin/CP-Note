/**
* dp
*/
class Solution
{
public:
    int numWays(int n, vector<vector<int>>& relation, int k)
    {
        // 有向图

        // 我的菜鸡做法
        // vector<vector<int>> dp(k, vector<int>(n));
        // for (const auto & r: relation)
        //     if (!r[0])
        //         dp[0][r[1]] = 1;
        // for (int i = 1; i < k; i++)
        //     for (const auto & r: relation)
        //     {
        //         int a = r[0];
        //         int b = r[1];
        //         dp[i][b] += dp[i-1][a];
        //     }
        // return dp[k-1][n-1];

        // 大佬做法
        // vector<vector<int>> dp(k+1, vector<int>(n));
        // dp[0][0] = 1;
        // for (int i = 1; i <= k; i++)
        //     for (const auto & r: relation)
        //         dp[i][r[1]] += dp[i-1][r[0]];
        // return dp[k][n-1];

        // 进行状态压缩
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i <= k; i++)
        {
            vector<int> nxt(n);
            for (const auto & r: relation)
                nxt[r[1]] += dp[r[0]];
            dp = nxt;
        }
        return dp[n-1];
    }
};