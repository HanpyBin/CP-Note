#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2960 lang=cpp
 *
 * [2960] 统计已测试设备
 */

// @lc code=start
class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size();
        int diff = 0;
        for (const int x : batteryPercentages) {
            if (x - diff <= 0)
                continue;
            diff++;
        }
        return diff;
    }
};
// @lc code=end

