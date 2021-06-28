/*
#include <vector>
#include <map>
#include <queue>
*/
class Solution
{
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target)
    {
        // Linklist
        // 连通图
        vector<int> flag(1e6+3);
        if (source == target)
            return 0;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < routes.size(); i++)
        {
            vector<int> temp = routes[i];
            for (int j = 0; j < temp.size(); j++)
            {
                m[temp[j]].push_back(i);
                flag[temp[j]] = 1;
            }
        }
        if (!flag[target])
            return -1;
        queue<int> q;
        vector<int> vis(1e6+3);
        q.push(source);
        vis[source] = 1;
        int res = 0;
        while (!q.empty())
        {
            int n = q.size();
            res++;
            while (n--)
            {
                int k = q.front();
                q.pop();
                for (int i = 0;i < m[k].size(); i++)
                {
                    vector<int> temp = routes[m[k][i]];
                    for (int j = 0; j < temp.size(); j++)
                    {
                        int x = temp[j];
                        if (x == target)
                            return res;
                        if (vis[x])
                            continue;
                        vis[x] = 1;
                        q.push(x);
                    }
                }
            }
        }
        return -1;
    }
};