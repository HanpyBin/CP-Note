/**
 * 倍增
 */

class Solution
{
public:
    int sum(vector<int>& row, int m)
    {
        int x = -1, y = 7;
        while (y >= 0)
        {
            if (x+(1<<y) < m && row[x+(1<<y)] == 1)
                x += (1<<y);
            y--;
        }
        return x + 1;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        vector<vector<int>> cnt(101);
        int m = mat[0].size();
        for (int i = 0; i < mat.size(); i++)
        {
            cnt[sum(mat[i], m)].push_back(i);
            // cout << sum(mat[i], m) << "< "<< i << endl;
        }
        vector<int> res;
        for (int i = 0; i <= 100; i++)
            for (int j = 0; j < cnt[i].size(); j++)
            {
                res.push_back(cnt[i][j]);
                if (--k <= 0)
                    return res;
            }
        return res;
    }
};