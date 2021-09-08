class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
    {
        priority_queue<int, vector<int>, less<int>> pq;
        vector<pair<int, int>> items;
        int n = profits.size();
        for (int i = 0; i < n; i++)
            items.push_back(make_pair(capital[i], profits[i]));
        sort(
            items.begin(),
            items.end(),
            [](const pair<int, int>& a, const pair<int, int>& b)
            {
                return a.first < b.first;
            }
        );

        int p = 0;
        for (int i = 0; i < k; i++)
        {
            while (items[p].first <= w && p < n)
            {
                pq.push(items[p].second);
                p++;
            }
            if (!pq.empty())
            {
                w += pq.top();
                pq.pop();
            }
            else
                break;
        }
        return w;
    }
};