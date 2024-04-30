#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2798 lang=cpp
 *
 * [2798] 满足目标工作时长的员工数目
 */

// @lc code=start
class Solution
{
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target)
    {
        int res = 0;
        for (const int& hour : hours)
            res += (hour >= target);
        return res;
    }
};
// @lc code=end

