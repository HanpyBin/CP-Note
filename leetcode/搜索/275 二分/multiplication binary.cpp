class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int x = 0;
        for (int b = citations.size(); b; b >>= 1)
            while (x + b <= citations.size() && citations[citations.size() - x - b] >= x + b)
                x += b;
        return x;
    }
};