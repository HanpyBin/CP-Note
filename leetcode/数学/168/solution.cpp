class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string res = "";
        while (columnNumber)
        {
            int t = columnNumber - 1;
            res = static_cast<char>(t%26+'A') + res;
            if (t%26 == 25)
                columnNumber -= 26;
            columnNumber /= 26;
        }
        return res;
    }
};