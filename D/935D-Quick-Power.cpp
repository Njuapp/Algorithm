//Created by Cheng Hang in 04/14/2018
#include <cstdio>
const int maxn = 1e5;
typedef long long int ll;
int a[maxn], b[maxn];
const int mod = 1e9+7;
int n,m;
ll quick_power(int m){
    int b = mod-2;
    ll  a = m;
    ll res = 1;
    while(b){
        if(b&1) res = res * a%mod;
        a = a*a%mod;
        b = b >> 1;
    }
    return res;
}
int  main(){
    scanf("%d%d", &n, &m);
    ll inv = quick_power(m);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    ll ans = 0;
    for(int i = n-1; i >= 0; i--){
        if(a[i] && b[i] == 0)
            ans = (a[i] - 1 + ans) * inv % mod;
        else if(a[i] == 0 && b[i])
            ans = (m - b[i] + ans) * inv % mod;
        else if(!a[i] && !b[i])
            ans = ((m*(m-1)/2) *inv %mod + ans) * inv %mod;
        else if(a[i] > b[i])
            ans = 1;
        else if(a[i] < b[i])
            ans = 0;
    }
    printf("%lld",ans);
    return 0;
}