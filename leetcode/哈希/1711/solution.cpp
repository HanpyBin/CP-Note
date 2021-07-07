class Solution
{
public:
    int countPairs(vector<int>& deliciousness)
    {
        // 判断2的幂，位运算，1-20
        long long res = 0;
        long long v = 1e9+7;
        unordered_map<int, int> m;
        for (const int & val: deliciousness)
            m[val]++;
        for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++)
        {
            int t = 1 << 22;
            int a = it->first;
            int val = it->second;
            for (int i = 0; i < 22; i++)
            {
                t >>= 1;
                int b = t - a;
                if (m.find(b) != m.end())
                    res += (long long)val * (m[b] - (a == b));
            }
        }
        res /= 2;
        return res % v;
    }
};