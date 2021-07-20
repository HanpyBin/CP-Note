class Solution
{
public:
    int minPairSum(vector<int>& nums)
    {
        int n = nums.size();
        int mini = INT_MIN;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n/2; i++)
        {
            int t = nums[i] + nums[n-1-i];
            if (t > mini)
                mini = t;
        }
        return mini;
    }
};