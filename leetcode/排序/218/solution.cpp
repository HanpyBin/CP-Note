class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        priority_queue<pair<int, int>> q;
        vector<vector<int>> res;
        int i = 0, n = buildings.size();
        int cur_x, cur_h;
        while (i < n || !q.empty())
        {
            if (q.empty() || i < n && buildings[i][0] <= q.top().second)
            {
                cur_x = buildings[i][0];
                while (i < n && cur_x == buildings[i][0])
                {
                    q.emplace(buildings[i][2], buildings[i][1]);
                    i++;
                }
            }
            else
            {
                cur_x = q.top().second;
                while (!q.empty() && cur_x >= q.top().second)
                    q.pop();
            }
            cur_h = q.empty() ? 0 : q.top().first;
            if (res.empty() || res.back()[1] != cur_h)
                res.push_back({cur_x, cur_h});
            cout << cur_x << ", " << cur_h << endl;
        }
        return res;

    }
};