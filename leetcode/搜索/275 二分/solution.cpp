class Solution
{
public:
    int hIndex(vector<int>& citations)
    {
        // binary search
        int left = 0, right = citations.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int len = citations.size() - mid;
            int val = citations[mid];
            if (!val)
            {
                left = mid + 1;
                continue;
            }
            if (len == val)
                return val;
            else if (len > val)
                left = mid + 1;
            else
                right = mid;
        }
        // cout << left << endl;
        if (citations[left])
            return citations.size() - left;
        else
            return 0;
    }
};