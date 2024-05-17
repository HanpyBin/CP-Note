#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=826 lang=cpp
 *
 * [826] 安排工作以达到最大收益
 */

// @lc code=start
struct Node
{
    int difficulty;
    int profit;
    Node(): difficulty(0), profit(0) {}
    Node(int d, int p): difficulty(d), profit(p) {}
};
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<Node> nodes(n);
        for (int i = 0; i < n; i++)
        {
            nodes[i].difficulty = difficulty[i];
            nodes[i].profit = profit[i];
        }
        sort(nodes.begin(), nodes.end(), [&](Node& a, Node& b) {
            if (a.profit > b.profit)
                return true;
            else if (a.profit < b.profit)
                return false;
            else
                return a.difficulty < b.difficulty;
        });
        sort(worker.begin(), worker.end(), greater<int>());
        int res = 0;
        int p = 0;
        for (int i = 0; i < worker.size(); i++)
        {
            while (p < n && worker[i] < nodes[p].difficulty)
                p++;
            if (p == n)
                break;
            res += nodes[p].profit;
        }
        return res;
    }
};
// @lc code=end

