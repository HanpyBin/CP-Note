class Solution
{
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right)
    {
        int n = ranges.size();
        if (!n)
            return false;
        sort(
            ranges.begin(),
            ranges.end(),
            [](vector<int>& a, vector<int>& b)
            {
                return a[0] < b[0];
            }
        );
        int l = ranges[0][0], r = ranges[0][1];
        for (const auto & range: ranges)
        {
            if (range[0] <= r+1)
            {
                r = max(range[1], r);
            }
            else
            {
                if (left >= l && right <= r)
                    return true;
                l = range[0];
                r = range[1];
            }
        }
        if (left >= l && right <= r)
            return true;
        return false;
    }
};