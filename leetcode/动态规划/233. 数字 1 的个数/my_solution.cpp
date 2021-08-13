class Solution
{
public:
    int countDigitOne(int n)
    {
        int x = n;
        int cnt = 0;
        int t = 1;
        vector<int> dp(11);
        vector<int> nums(11);
        while (x)
        {
            cnt++;
            nums[cnt] = x % 10;
            x /= 10;
            if (!x)
                continue;
            dp[cnt] = 10*dp[cnt-1] + t;
            t *= 10;
        }
        int res = 0;
        int num1 = 0;
        for (int i = cnt; i >= 1; i--)
        {
            n -= nums[i] * t;
            if (nums[i] > 1)
                res += nums[i]*dp[i-1] + t;
            else if (nums[i] == 1)
                res += dp[i-1] + n + 1;
            t /= 10;
        }
        return res;
    }
};