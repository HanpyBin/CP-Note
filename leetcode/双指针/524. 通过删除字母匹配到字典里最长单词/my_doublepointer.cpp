class Solution
{
public:

    bool check(string a, string b)
    {
        int p = 0;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == b[p])
                p++;
            if (p == b.length())
                return true;
        }
        if (p != b.length())
            return false;
        else
            return true;
    }

    string findLongestWord(string s, vector<string>& dictionary)
    {
        sort(
            dictionary.begin(),
            dictionary.end(),
            [](string &a, string &b)
            {
                if (a.length() < b.length())
                    return false;
                else if (a.length() == b.length())
                {
                    if (a < b)
                        return true;
                    else
                        return false;
                }
                else
                    return true;
            }
        );
        for (int i = 0; i < dictionary.size(); i++)
        {
            if (check(s, dictionary[i]))
                return dictionary[i];
        }
        return "";
    }
};