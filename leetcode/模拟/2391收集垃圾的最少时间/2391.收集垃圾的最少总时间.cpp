#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=2391 lang=cpp
 *
 * [2391] 收集垃圾的最少总时间
 */

// @lc code=start
class Solution
{
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel)
    {
        const int car_num = 3;
        int n = garbage.size();
        vector<int> end_pos(car_num, -1);
        unordered_map<char, int> dict;
        dict['M'] = 0;
        dict['P'] = 1;
        dict['G'] = 2;
        int res = garbage[0].length();
        for (int i = 1; i < n; i++)
        {
            res += garbage[i].length();
            for (int j = 0; j < garbage[i].length(); j++)
                end_pos[dict[garbage[i][j]]] = i;
        }
        for (int i = 1; i < n-1; i++)
            travel[i] += travel[i-1];
        for (int i = 0; i < car_num; i++)
            res += (end_pos[i] == -1 ? 0 : travel[end_pos[i]-1]);
        return res;
    }
};
// @lc code=end

