class Solution
{
public:
    vector<int> u, v;
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target)
    {
        int m = graph.size();
        vector<vector<int>> routes(n);
        for (int i = 0; i < m; i++)
        {
            int a = graph[i][0];
            routes[a].push_back(i);
        }
        // bfs
        vector<int> vis(n);
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while (!q.empty())
        {
            int k = q.front();
            q.pop();
            for (int i = 0; i < routes[k].size(); i++)
            {
                int v = graph[routes[k][i]][1];
                if (v == target)
                    return true;
                if (vis[v])
                    continue;
                vis[v] = 1;
                q.push(v);
            }
        }
        return false;
    }
};