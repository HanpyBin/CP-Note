class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<multiset<char>, int> um;
        vector<vector<string>> res;
        int cnt = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            multiset<char> chs;
            for (const auto & ch: temp)
            {
                chs.insert(ch);
            }
            if (um.find(chs) == um.end())   // 不存在这样的集合
            {
                um[chs] = cnt++;
                vector<string> t;
                t.push_back(temp);
                res.push_back(t);
            }
            else
            {
                int x = um[chs];
                res[x].push_back(temp);
            }
        }
        return res;
    }
};