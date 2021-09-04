class Solution
{
public:
    int fib(int n)
    {
        // f(0) = 0, f(1) = 1, f(2) = 1
        if (!n)
            return 0;
        else if (1 == n)
            return 1;
        
        int a = 0, b = 1;
        int mod = 1e9 + 7;
        int i = 1;
        while (i != n)
        {
            int c = (a%mod + b%mod)%mod;
            a = b;
            b = c;
            i++;
        }
        return b;
    }
};