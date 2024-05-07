#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1463 lang=cpp
 *
 * [1463] 摘樱桃 II
 */

// @lc code=start
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // dp[i][j][k] = max(
        //  dp[i-1][j+1][k+1],
        //  dp[i-1][j+1][k],
        //  dp[i-1][j+1][k-1],
        //  dp[i-1][j][k+1],
        //  dp[i-1][j][k],
        //  dp[i-1][j][k-1],
        //  dp[i-1][j-1][k+1],
        //  dp[i-1][j-1][k],
        //  dp[i-1][j-1][k-1],
        //  )
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        // vector<int> op = {-1, 0, 1};
        vector<vector<int>> op = {
            {1, 1}, {1, 0}, {1, -1},
            {0, 1}, {0, 0}, {0, -1},
            {-1, 1}, {-1, 0}, {-1, -1}
        };
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                if (j != k)
                    dp[n-1][j][k] = grid[n-1][j] + grid[n-1][k];
                else
                    dp[n-1][j][k] = grid[n-1][j];
            }
        }
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    int val = -1;
                    for (int p = 0; p < op.size(); p++) {
                        int tj = j + op[p][0];
                        int tk = k + op[p][1];
                        if (tj < 0 || tk < 0 || tj == m || tk == m)
                            continue;
                        val = max(val, dp[i+1][tj][tk]);
                    }
                    dp[i][j][k] = val + grid[i][j];
                    if (j != k)
                        dp[i][j][k] += grid[i][k];
                }
            }
        }
        return dp[0][0][m-1];
    }
};
// @lc code=end

