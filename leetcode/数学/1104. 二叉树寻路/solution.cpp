class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        // 1 < log2(3) < 2
        // (1) (2, 3) (4,5,6,7)
        // 1, 5, 11 = 4 + (8-1)
        // 3 < log2(14) < 4
        // 8+(16-1) = 23
        // 14
        // 4+(8-1) = 11
        // 11 - 14/2 = 4
        // 2+(4-1) = 5
        // 5-4/2=3
        // 1+(2-1) = 2
        // 2-3/2 = 1
        int n = ceil(log(label+1) / log(2));
        // cout << n << endl;
        // cout << n << endl;
        int m = pow(2, n-1);
        stack<int> s;
        while (n--)
        {
            s.push(label);
            // cout << m << endl;
            label = (m>>1) + (m-1) - (label>>1);
            m >>= 1;
        }
        vector<int> res;
        while (!s.empty())
        {
            int k = s.top();
            s.pop();
            res.push_back(k);
        }
        return res;
    }
};