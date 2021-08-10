class Solution
{
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;
        int diff = nums[1] - nums[0];
        int cur_len = 2;
        int res = 0;
        for (int i = 2; i < n; i++)
        {
            // 计算最长等差数列
            if (nums[i] - nums[i-1] == diff)
                cur_len++;
            else
            {
                res += (cur_len-1) * (cur_len-2) / 2;
                cur_len = 2;
                diff = nums[i] - nums[i-1];
            }
            // 添加结果
        }
        res += (cur_len-1) * (cur_len-2) / 2;
        return res;
    }
};
// 4 -> 2 + 1 -> (1+...(cur_len-2))*(cur_len-2)/2