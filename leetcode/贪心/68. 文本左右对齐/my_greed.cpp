class Solution
{
public:
    string fulfill(vector<int>& v, vector<string>& words, vector<int>& lens, int tot, int maxWidth)
    {
        int n = v.size();
        int re = maxWidth - tot;
        string res = words[v[0]];
        if (n > 1)
        {
            int interval = re / (n-1); // 单词之间的blank
            int cnt = re - (n-1) * interval;
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < interval; j++)
                    res += " ";
                if (cnt-- > 0)
                    res += " ";
                res += words[v[i]];
            }
        }
        else
        {
            for (int i = 0; i < re; i++)
                res += " ";
        }
        return res;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> res;
        vector<int> v;
        vector<int> lens;
        int tot = 0;
        // 分段，每段都是小于等于maxWidth
        for (int i = 0; i < words.size(); i++)
        {
            if (tot + words[i].length() + v.size() > maxWidth)
            {
                string temp = fulfill(v, words, lens, tot, maxWidth);
                res.push_back(temp);
                v.clear();
                lens.clear();
                tot = 0;
            }
            tot += words[i].length();
            v.push_back(i);
            lens.push_back(words[i].length());
        }
        string str = words[v[0]];
        for (int i = 1; i < v.size(); i++)
            str += " " + words[v[i]];
        int x = str.length();
        for (int i = 0; i < maxWidth - x; i++)
            str += " ";
        res.push_back(str);
        return res;
    }
};