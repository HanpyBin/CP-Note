class Solution
{
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right)
    {
        vector<int> diff(52, 0);
        for (const auto & range: ranges)
        {
            diff[range[0]]++;
            diff[range[1]+1]--;
        }
        int cnt = 0;
        for (int i = 0; i < 52; i++)
        {
            cnt += diff[i];
            if (i >= left && i <= right && cnt <= 0)
                return false;
        }
        return true;
    }
};