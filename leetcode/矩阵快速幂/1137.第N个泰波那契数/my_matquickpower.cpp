class Solution
{
public:
    int tribonacci(int n)
    {
        vector<vector<long>> res(3, vector<long>(3));
        vector<vector<long>> temp(3, vector<long>(3));
        res[0][0] = res[1][1] = res[2][2] = 1;
        temp[0][0] = temp[0][1] = temp[0][2] = 1;
        temp[1][0] = temp[2][1] = 1;
        res = QuickPower(res, temp, n, 3);
        return res[0][2];
    }
    vector<vector<long>> QuickPower(vector<vector<long>>& res, vector<vector<long>>& temp, int n, int m)
    {
        while (n)
        {
            if (n&1)
                res = MatMul(res, temp, m);
            temp = MatMul(temp, temp, m);
            n >>= 1;
        }
        return res;
    }

    vector<vector<long>> MatMul(vector<vector<long>>& a, vector<vector<long>>& b, int m)
    {
        vector<vector<long>> t(m, vector<long>(m));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < m; k++)
                    t[i][j] += a[i][k] * b[k][j];
        return t;
    }
};