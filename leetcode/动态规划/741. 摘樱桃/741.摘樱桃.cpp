#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=741 lang=cpp
 *
 * [741] 摘樱桃
 */

// @lc code=start
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> memo(n*2-1, vector<vector<int>>(n, vector<int>(n, -1)));
        function<int(int, int, int)> dfs = [&](int t, int j, int k) -> int {
            if (j < 0 || k < 0 || t < j || t < k || grid[t-j][j] < 0 || grid[t-k][k] < 0)
                return INT_MIN;
            if (!t)
                return grid[0][0];
            int& res = memo[t][j][k];
            if (res != -1)
                return res;
            return res = max({dfs(t-1, j, k), dfs(t-1, j-1, k), dfs(t-1, j, k-1), dfs(t-1, j-1, k-1)}) + 
                grid[t-j][j] + (j == k ? 0 : grid[t-k][k]);
        };
        return max(dfs(n*2-2, n-1, n-1), 0);
    }
};
// @lc code=end

