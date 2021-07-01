/**
 * BFS
*/
class Solution
{
public:
    int numWays(int n, vector<vector<int>>& relation, int k)
    {
        // 有向图
        vector<vector<int>> m(n);
        for (const auto & rela: relation)
            m[rela[0]].push_back(rela[1]);
        queue<int> q;
        q.push(0);
        int cnt = 0;
        int res = 0;
        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                int temp = q.front();
                // cout << cnt << "," << temp << endl;
                q.pop();
                for (int i = 0; i < m[temp].size(); i++)
                {
                    int t = m[temp][i];
                    if (t == n-1 && cnt == k-1)
                        res++;
                    q.push(t);
                }
            }
            if (++cnt > k)
                break;
        }
        return res;
    }
};