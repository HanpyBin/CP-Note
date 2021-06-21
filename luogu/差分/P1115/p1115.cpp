#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 2e5+5;

int main()
{
    int n;
    int x;
    scanf("%d", &n);
    scanf("%d", &x);
    int res = x;
    int temp = res;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &x);
        temp = max(temp+x, x);
        if (temp > res)
            res = temp;
    }
    printf("%d", res);
    return 0;
}