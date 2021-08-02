struct cmp1{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
            return a.first > b.first;
    }
};

class Solution
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        int m = times.size();
        vector<vector<int>> routes(n+1);
        for (int i = 0; i < m; i++)
            routes[times[i][0]].push_back(i);
        // 优先队列
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1> q;
        vector<int> vis(n+1);
        q.push(make_pair(0, k));
        int ct = -1;
        while (!q.empty())
        {
            pair<int, int> temp = q.top();
            int from = temp.second;
            // cout << "from=" << from << " cost=" << ct << endl;
            q.pop();
            if (vis[from])
                continue;
            ct = temp.first;
            vis[from] = 1;
            n--;
            for (int i = 0; i < routes[from].size(); i++)
            {
                int to = times[routes[from][i]][1];
                int cost = times[routes[from][i]][2];
                if (!vis[to])
                {
                    q.push({ct+cost, to});
                    // cout << ct+cost << ", " << to << endl;
                }
            }
        }
        if (n)
            return -1;
        return ct;
    }
};