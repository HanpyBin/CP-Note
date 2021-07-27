class Solution
{
public:
    int insertBits(int N, int M, int i, int j)
    {
        // 位运算就好了啊
        long long x = 1;
        x = (x << 31) - 1;
        long long t = 1;
        for (int a = 0; a < i; a++)
            t <<= 1;
        for (int a = i; a <= j; a++)
        {
            x -= t;
            if (a == j)
                continue;
            t <<= 1;
        }
        // cout << (x & N) << endl;
        // cout << (M << i) << endl;
        return (x & N) + (M << i);
    }
};