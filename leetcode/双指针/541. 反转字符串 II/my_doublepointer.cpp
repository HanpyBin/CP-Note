class Solution
{
public:
    void Reverse(string& s, int p, int q)
    {
        while (p < q)
        {
            char t = s[p];
            s[p] = s[q];
            s[q] = t;
            p++;
            q--;
        }
    }
    string reverseStr(string s, int k)
    {
        int len = s.length();
        int r = round(len / 2.0 / k);
        int p, q;
        for (int i = 0; i < r; i++)
        {
            p = 2 * i * k;
            q = (2*i + 1) * k - 1;
            Reverse(s, p, q);
        }
        if (2*k*r < len)
        {
            p = 2*r*k;
            q = len-1;
            Reverse(s, p, q);
        }
        return s;
    }
};