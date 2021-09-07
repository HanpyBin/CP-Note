class Solution
{
public:
    int balancedStringSplit(string s)
    {
        char ch = s[0];
        int cnt = 0, res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (!cnt)
            {
                ch = s[i];
                cnt++;
            }
            else
            {
                if (s[i] == ch)
                    cnt++;
                else
                    cnt--;
                if (!cnt)
                    res++;
            }
        }
        return res;
    }
};