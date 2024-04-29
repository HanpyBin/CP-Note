#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 *
 * [1329] 将矩阵按对角线排序
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int dig_cnt = n + m - 1;
        vector<vector<int>> digs(dig_cnt);
        const int pad = n - 1;
        vector<pair<int, int>> start_pos;
        for (int i = n-1; i >= 0; i--)
            start_pos.push_back({i, 0});
        for (int i = 1; i < m; i++)
            start_pos.push_back({0, i});
        for (int k = 0; k <= dig_cnt; k++)
        {
            vector<int> t;
            int x = start_pos[k].first;
            int y = start_pos[k].second;
            while (x >= 0 && y >= 0 && x < n && y < m)
                t.push_back(mat[x++][y++]);
            sort(t.begin(), t.end());
            x = start_pos[k].first;
            y = start_pos[k].second;
            int p = 0;
            while (x >= 0 && y >= 0 && x < n && y < m)
                mat[x++][y++] = t[p++];
        }
        return mat;
    }
};
// @lc code=end

