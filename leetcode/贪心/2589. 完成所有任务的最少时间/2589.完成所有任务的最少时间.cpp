#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=2589 lang=cpp
 *
 * [2589] 完成所有任务的最少时间
 */

// @lc code=start
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [&](auto& a, auto& b) {return a[1] < b[1];});
        vector<int> run(tasks[n-1][1]+1);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int st = tasks[i][0];
            int ed = tasks[i][1];
            int timing = tasks[i][2];
            timing -= accumulate(run.begin()+st, run.begin()+ed+1, 0);
            for (int i = ed; i >= st && timing > 0; i--)
            {
                if (!run[i])
                {
                    run[i] = 1;
                    timing--;
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

