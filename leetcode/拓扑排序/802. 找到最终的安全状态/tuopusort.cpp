class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        // 拓扑排序
        int n = graph.size();
        vector<vector<int>> in(n);
        vector<int> outdegree(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < graph[i].size(); j++)
            {
                in[graph[i][j]].push_back(i);
                outdegree[i]++;
            }
        vector<int> res;
        for (int i = 0; i < n; i++)
            if (!outdegree[i])
                res.push_back(i);
        int p = 0, q = res.size();
        while (p != q)
        {
            int k = res[p];
            for (int i = 0; i < in[k].size(); i++)
            {
                int t = in[k][i];
                outdegree[t]--;
                if (!outdegree[t])
                {
                    res.push_back(t);
                    q++;
                }
            }
            p++;
        }
        sort(res.begin(), res.end());
        return res;
    }
};