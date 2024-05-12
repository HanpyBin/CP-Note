#include <vector>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=1553 lang=cpp
 *
 * [1553] 吃掉 N 个橘子的最少天数
 */

// @lc code=start
const int maxn = 2e9+2;
class Solution
{
private:
    unordered_map<int, int> num_day_dict;
public:
    int dfs(int n)
    {
        int res = maxn;
        if (!n)
            return num_day_dict[0] = 0;
        if (n == 1)
        {
            return num_day_dict[1] = 1;
        }
        // if (num_day_dict.find(n-1) != num_day_dict.end())
        //     res = min(res, num_day_dict[n-1]);
        // else
        //     res = min(dfs(n-1), res);
        // if (n % 2 == 0)
        // {
        //     if (num_day_dict.find(n/2) != num_day_dict.end())
        //         res = min(res, num_day_dict[n/2]);
        //     else
        //         res = min(dfs(n/2), res);
        // }
        // if (n % 3 == 0)
        // {
        //     if (num_day_dict.find(n/3) != num_day_dict.end())
        //         res = min(res, num_day_dict[n/3]);
        //     else
        //         res = min(res, dfs(n/3));
        // }
        if (num_day_dict.find(n/2) != num_day_dict.end())
            res = min(res, num_day_dict[n/2] + n - n/2*2);
        else
            res = min(dfs(n/2)+ n - n/2*2, res);
        if (num_day_dict.find(n/3) != num_day_dict.end())
            res = min(res, num_day_dict[n/3] + n - n/3*3);
        else
            res = min(res, dfs(n/3) + n - n/3*3);
        return num_day_dict[n] = res + 1;
    }
    int minDays(int n)
    {
        return dfs(n);
    }
};
// @lc code=end

