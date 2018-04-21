#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <iostream>
typedef long long ll;

using namespace std;
const int maxn = 30001;
int n, d;
int gems[maxn];
int dp[250*2][maxn];
int sub(int l, int island){
    if(island >= maxn)
        return 0;
    return dp[l-d+250][island];
}
void solve(int l, int island){
    int res;
    if(l == 1)
        res = gems[island] + max(sub(l,island+l), sub(l+1, island+l+1));
    else
        res = gems[island] + max(max(sub(l-1,island+l-1), sub(l,island+l)), sub(l+1,island+l+1));
    dp[l-d+250][island] = res;
}
int main()
{
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        gems[tmp]++;
    }
    for(int i = maxn - 1; i >= 0; i --){
        for(int j = max(0,d - 245); j < d + 245; j ++)
            solve(j, i);
    }
    printf("%d", sub(d,d));
    return 0;
}