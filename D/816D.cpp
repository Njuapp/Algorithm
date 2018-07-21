#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
const int N= 200005;
int n;
ll a[N];
const int MOD = (int)1e9 + 7;
ll F[N], Finv[N], inv[N];//F是阶乘，Finv是逆元的阶乘
void init(){
    inv[1] = 1;
    for(int i = 2; i < N; i ++){
        inv[i] = (MOD - MOD / i) * 1ll * inv[MOD % i] % MOD;
    }
    F[0] = Finv[0] = 1;
    for(int i = 1; i < N; i ++){
        F[i] = F[i-1] * 1ll * i % MOD;
        Finv[i] = Finv[i-1] * 1ll * inv[i] % MOD;
    }
}
ll comb(int n, int m){//comb(n, m)就是C(n, m)
    if(m < 0 || m > n) return 0;
    return F[n] * 1ll * Finv[n - m] % MOD * Finv[m] % MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    init();
    forn(i,n)
        cin >> a[i];
    if(n == 1){
        cout<<a[0];
        return 0;
    }
    if(n % 2){
        forn(i,n-1){
            if(i % 2 == 0)
                a[i] = a[i] + a[i+1];
            else
                a[i] = a[i] - a[i+1];
        }
        n--;
    }
    int ope = (n % 4 == 0 ? -1 : 1);
    ll ans = 0;
    for(int i = 0; i < n ; i +=2){
        ll temp = comb(n / 2 - 1,i / 2);
        ans += temp*(a[i] + ope*a[i + 1]) % MOD;
        ans %= MOD;
    }
    ans = (ans %MOD + MOD) %MOD;
    cout<<ans;
    return 0;
}