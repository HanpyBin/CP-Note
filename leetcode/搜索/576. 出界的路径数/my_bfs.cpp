class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        int res = 0;
        vector<vector<int>> cnt(m, vector<int>(n));
        vector<vector<int>> nxt(4, vector<int>(2));
        // (1, 0), (0, 1), (-1, 0), (0, -1)
        nxt[1][1] = nxt[0][0] = 1;
        nxt[2][0] = nxt[3][1] = -1;
        queue<pair<int, int>> q;
        q.push(make_pair(startRow, startColumn));
        cnt[startRow][startColumn]++;
        while (!q.empty() && maxMove--)
        {
            vector<vector<int>> vis(m, vector<int>(n, 0));
            int x = q.size();
            while (x--)
            {
                pair<int, int> t = q.front();
                q.pop();
                int row = t.first;
                int col = t.second;
                for (int k = 0; k < 4; k++)
                {
                    int r = row + nxt[k][0];
                    int c = col + nxt[k][1];
                    if (r < 0 || c < 0 || r >= m || c >= n)
                    {
                        res = (res+(cnt[row][col]%1000000007))%1000000007;
                        continue;
                    }
                    if (!vis[r][c])
                        q.push(make_pair(r, c));
                    vis[r][c] = (vis[r][c] + (cnt[row][col] % 1000000007))%1000000007;
                }
            }
            cnt = vis;
        }
        return res;
    }
};