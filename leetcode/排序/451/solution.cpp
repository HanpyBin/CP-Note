class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<int, int> record;
        for (auto s_: s)
            record[s_]++;
        vector<pair<int, int>> res;
        for (auto re: record)
            res.push_back(make_pair(re.first, re.second));
        sort(
            res.begin(),
            res.end(),
            [](pair<int, int> &a, pair<int, int> &b)
            {
                return a.second > b.second;
            }
        );
        string result = "";
        for (auto i = res.begin(); i != res.end(); i++)
            for (int j = 0; j < i->second; j++)
                result += i->first;
        return result;
        // int max_count = 0;
        // unordered_map<int, int> record;
        // for (auto s_: s)
        //     max_count = max(++record[s_], max_count);
        // vector<vector<int>> buckets(max_count+1);
        // for (auto p: record)
        //     buckets[p.second].push_back(p.first);

        // string res = "";
        // for (int i = max_count; i >= 0; i--)
        //     for (int j = 0; j < buckets[i].size(); j++)
        //         for (int k = 0; k < i; k++)
        //             res += buckets[i][j];

        // return res;
    }
};