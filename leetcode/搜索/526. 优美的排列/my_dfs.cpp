class Solution
{
public:
    int res;
    void Dfs(vector<vector<int>>& vis, vector<int> cnt, int ind, int& n)
    {
        if (ind == n)
        {
            res++;
            return;
        }
        for (int i = 1; i < n+1; i++)
            if (vis[ind+1][i] && !cnt[i])
            {
                cnt[i] = 1;
                Dfs(vis, cnt, ind+1, n);
                cnt[i] = 0;
            }
        return;
    }
    int countArrangement(int n)
    {
        // vector<vector<vector<int>>> vis(16, vector<vector<int>(2, vector<int>(16)));
        res = 0;
        vector<vector<int>> vis(n+1, vector<int>(n+1));
        for (int i = 1; i < n+1; i++)
            for (int j = 1; j < n+1; j++)
            {
                if (!(i % j))
                    // vis[i][0][j] = 1;
                    vis[i][j] = 1;
                if (!(j % i))
                    vis[i][j] = 1;
            }
        vector<int> cnt(16);
        Dfs(vis, cnt, 0, n);
        return res;
    }
};