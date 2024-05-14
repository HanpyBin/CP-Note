#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=2244 lang=cpp
 *
 * [2244] 完成所有任务需要的最少轮数
 */

// @lc code=start
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // if x % 2 == 0
        //  res = res + res / 6 * 2
        const int maxn = 1e5 + 1;
        int res = 0;
        // vector<int> cnt(maxn, 0);
        unordered_map<int, int> cnt;
        for (const auto x : tasks)
            cnt[x]++;
        for (auto& [k, t] : cnt)
        {
            if (t == 1)
                return -1;
            if (t & 1)
            {
                t -= 3;
                res++;
            }
            res += t / 6 * 2;
            t = t - t / 6 * 6;
            res += t / 2;
        }
        return res;
    }
};
// @lc code=end

