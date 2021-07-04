class Solution
{
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> res(2, -2);
        // 排序很简单
        sort(nums.begin(), nums.end());
        int cur = 1;
        for (int i = 0; i < n-1; i++)
        {
            if (nums[i] == nums[i+1])
                res[0] = nums[i];
            if (nums[i] == cur)
                cur++;
        }
        if (nums[n-1] == cur)
            cur++;
        res[1] = cur;
        return res;
    }
};
// 1 2 2 3 4 5 6 7 8 9
// 1 2 2 3 4 5 6 7 9 10