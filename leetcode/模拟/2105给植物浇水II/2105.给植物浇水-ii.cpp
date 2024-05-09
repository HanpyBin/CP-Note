class Solution
{
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB)
    {
        int n = plants.size();
        int p = 0, q = n-1;
        int res = 0;
        int ca = capacityA;
        int cb = capacityB;
        bool flag = true;
        while (p <= q)
        {
            if (flag)
            {
                if (p == q)
                {
                    if (max(ca, cb) < plants[p])
                        res++;
                    q = p-1;
                }
                else
                {
                    if (ca < plants[p])
                    {
                        ca = capacityA;
                        res++;
                    }
                    ca -= plants[p++];
                }
            }
            else
            {
                if (cb < plants[q])
                {
                    cb = capacityB;
                    res++;
                }
                cb -= plants[q--];
            }
            flag = !flag;
        }
        return res;
    }
};