class Solution
{
public:
    int maxIceCream(vector<int>& costs, int coins)
    {
        // int n = costs.size();
        // vector<int> dp(coins+1);
        // for (int i = 1; i <= n; i++)
        //     for (int j = coins; j >= 0; j--)
        //         if (j+costs[i-1] <= coins)
        //             dp[j] = max(dp[j+costs[i-1]]+1, dp[j]);
        // return dp[0];
        sort(costs.begin(), costs.end());
        int res = 0;
        int n = costs.size();
        for (int i = 0; i < n; i++)
        {
            coins -= costs[i];
            if (coins < 0)
                return i;
        }
        return n;
    }
};