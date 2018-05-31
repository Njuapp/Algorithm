#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 50;
typedef pair<int,int> pii;
int n,k;
ll a[maxn];
int dp[55][55];
ll sum[55];
int check(ll val){
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++){
        if((sum[i] & val) == val) dp[i][1] = 1;
        for(int j = 1; j < i; j ++){
            if(((sum[i] - sum[j]) & val) != val) continue;
            for(int h = 2; h <= min(i, k); h ++)
                dp[i][h] |= dp[j][h-1];
        }
    }
    return dp[n][k];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    forn(i,n){
        cin >> a[i];
        sum[i+1]  = sum[i] + a[i];
    }
    ll ans = 0;
    for(int k = 60; k >= 0; k --){
        if(check((ans | (1LL<< k)))) ans |= (1LL << k);
    }
    cout<<ans<<endl;
    return 0;
}