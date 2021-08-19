class Solution
{
public:
    bool check(char ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s)
    {
        int p = 0, q = s.length() - 1;
        while (p < q)
        {
            while (p < q && !check(s[p]))
                p++;
            while (p < q && !check(s[q]))
                q--;
            if (p < q)
            {
                char t = s[p];
                s[p] = s[q];
                s[q] = t;
                p++;
                q--;
            }
        }
        return s;
    }
};