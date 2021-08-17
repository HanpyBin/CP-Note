class Solution
{
public:
    bool checkRecord(string s)
    {
        int cntA = 0;
        int cntL = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A')
            {
                cntA++;
                if (cntA > 1)
                    return false;
            }
            else if (s[i] == 'L')
            {
                cntL++;
                if (cntL == 3 && s[i-1] == 'L' && s[i-2] == 'L')
                    return false;
                continue;
            }
            cntL = 0;
        }
        return true;
    }
};