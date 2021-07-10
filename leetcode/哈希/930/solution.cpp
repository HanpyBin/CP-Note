class Solution
{
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        int n = nums.size();
        unordered_map<int, int> m;
        int sum = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            m[sum]++;
            sum += nums[i];
            res += m[sum-goal];
        }
        return res;
    }
};