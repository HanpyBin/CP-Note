#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1535 lang=cpp
 *
 * [1535] 找出数组游戏的赢家
 */

// @lc code=start
class Solution
{
public:
    int getWinner(vector<int>& arr, int k)
    {
        // 如果遍历一次没有找出来，那答案就是最大值
        int n = arr.size();
        int a = arr[0], b;
        int d = arr[0];
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            d = max(d, arr[i]);
            if (arr[i] > a) // 重置
            {
                cnt = 1;
                a = arr[i];
            }
            else
            {
                cnt++;
            }
            if (cnt == k)
                return a;
        }
        return d;
    }
};
// @lc code=end

