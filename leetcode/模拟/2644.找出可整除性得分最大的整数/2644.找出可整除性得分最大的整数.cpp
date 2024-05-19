#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2644 lang=cpp
 *
 * [2644] 找出可整除性得分最大的整数
 */

// @lc code=start
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        // 可以判断一下divisors中的bind pair
        int mres = 0;
        int indres = divisors[0];
        for (const auto& d: divisors)
        {
            int res = 0;
            for (const auto& x: nums)
                if (x % d == 0)
                    res++;
            if (mres > res)
            {
                mres = max(res, mres);
                indres = d;
            }
            else if (mres == res && d < indres)
                indres = d;
        }
        return indres;
    }
};
// @lc code=end

