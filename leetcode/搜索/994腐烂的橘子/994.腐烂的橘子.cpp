using PII = pair<int, int>;
class Solution
{
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int fresh = 0;
        queue<PII> q;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    fresh++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        vector<vector<int>> nxt = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int res = 0;
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                auto t = q.front();
                q.pop();
                int x = t.first;
                int y = t.second;
                for (int k = 0; k < 4; k++)
                {
                    int tx = x + nxt[k][0];
                    int ty = y + nxt[k][1];
                    if (tx < 0 || ty < 0 || tx == n || ty == m)
                        continue;
                    if (grid[tx][ty] == 1)
                    {
                        fresh--;
                        q.push({tx, ty});
                        grid[tx][ty] = 0;
                    }
                }
            }
            if (q.size() > 0)
                res++;
        }
        return fresh ? -1 : res;
    }
};