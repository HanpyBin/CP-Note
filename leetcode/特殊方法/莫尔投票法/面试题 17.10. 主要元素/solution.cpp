class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        if (!n)
            return -1;
        int num;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!cnt)
                num = nums[i];
            if (nums[i] == num)
                cnt++;
            else
                cnt--;
        }
        cnt = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] == num)
                cnt++;
        if (2 * cnt > n)
            return num;
        else
            return -1;
    }
};