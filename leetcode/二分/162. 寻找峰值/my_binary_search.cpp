class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        else if (nums[n-1] > nums[n-2])
            return n-1;
        int l = 0, r = nums.size()-1;
        while (l + 2 != r)
        {
            int mid = l + (r-l)/2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            if ((nums[mid-1] - nums[mid]) * (nums[l+1] - nums[l]) > 0)
                r = mid;
            else if ((nums[mid+1] - nums[mid]) * (nums[r-1] - nums[r]) > 0)
                l = mid;
        }
        return l+1;
    }
};