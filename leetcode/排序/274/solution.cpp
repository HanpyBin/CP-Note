class Solution
{
public:
    int hIndex(vector<int>& citations)
    {
        // 更新为一个集合中的最小值
        // 维护一个最小值和最小数量
        priority_queue<int, vector<int>, greater<int>> q;
        int res = 0;
        int p = 0;
        while (p < citations.size() && !citations[p])
            p++;
        if (p == citations.size())
            return 0;
        res++;
        q.push(citations[p]);
        for (int i = p+1; i < citations.size(); i++)
        {
            int n = q.size();
            int mini = q.top();
            int m = min(n, mini);
            if (citations[i] >= m)
                q.push(citations[i]);
            if (q.size() > q.top())
                q.pop();
            // cout << q.top() << "," << q.size() << endl;
        }
        return min(int(q.size()), q.top());
    }
};
// 5 7 8 10