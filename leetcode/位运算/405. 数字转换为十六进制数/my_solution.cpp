class Solution
{
public:
    string toHex(int num)
    {
        if (!num)
            return "0";
        string ans;
        string ch = "0123456789abcdef";
        for (int i = 7; i >= 0; i--)
        {
            int val = (num >> (4*i)) & 0xf;
            if (val || !ans.empty())
            {
                // cout << val << endl;
                ans.push_back(ch[val]);
            }
        }
        return ans;
    }
};