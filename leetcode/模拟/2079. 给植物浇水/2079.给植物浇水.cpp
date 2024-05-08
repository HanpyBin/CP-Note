#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=2079 lang=cpp
 *
 * [2079] 给植物浇水
 */

// @lc code=start
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int cp = capacity;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (cp < plants[i]) {
                cp = capacity - plants[i];
                res = res + 2 * i + 1;
            } else {
                cp = cp - plants[i];
                res++;
            }
            // cout << res << endl;
        }
        return res;
    }
};
// @lc code=end

