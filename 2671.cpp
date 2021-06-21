#include <iostream>
using namespace std;

const int maxn = 1e5+3;
int main()
{ 
    int n, m;
    int number[maxn], color[maxn];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &number[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &color[i]);
    // 如果用枚举肯定会超时
    // 只要x和y同为奇/偶就行
    
    return 0;
}
