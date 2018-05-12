#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[5005], p[5005], ans[5005];
int n;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n ; i++)
        scanf("%d",&a[i]);
    for(int i = 1; i <= n; i++){
        if(a[i] == 0)continue;
        for(int y = 2; y <= 10000; y++){
            while(a[i] % (y*y) == 0)
                a[i] /= (y*y);
        }
    }
    for(int i = 1; i <= n; i ++)
        p[i] = a[i];
    sort(p+1, p+n+1);
    int cnt = unique(p+1, p + n+1) - p - 1;
    for(int i = 1; i <= n; i++)
        a[i] = lower_bound(p+1, p + cnt + 1, a[i]) - p;
    int ids = lower_bound(p+1, p + cnt + 1, 0) - p;
    if(p[ids])
        ids = -1;
    for(int i = 1; i <= n; i++){
        int now = 0;
        memset(p, 0, sizeof(p));
        for(int j = i; j <= n; j ++){
            if(a[j] != ids && p[a[j]] == 0)
                now++;
            p[a[j]] = 1;
            ans[max(1, now)] ++;
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}