#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
const int mod = 1000000007;
using namespace std;
ll n, m;
ll k;
int x;
const int maxn = 100010;
const int maxx = 12;
ll dp[maxn][maxx][3];
vector<int> arcs[maxn];
int sz[maxn];
ll tmp[maxx][3];
void dfs(int n, int pa){
    dp[n][0][0] = k-1;
    dp[n][1][1] = 1;
    dp[n][0][2] = m-k;
    sz[n] = 1;
    for(int i = 0; i < arcs[n].size(); i++){
        int to = arcs[n][i];
        if(to== pa)
            continue;
        dfs(to, n);
        memset(tmp, 0, sizeof(tmp));
        for(int j = 0; j <= sz[n]; j++){
            for(int s = 0; s <= sz[to]; s ++){
                if( j + s > x)
                    break;
                tmp[j+s][0] += dp[n][j][0]*(dp[to][s][0] + dp[to][s][1] + dp[to][s][2]) % mod;
                tmp[j+s][0] %= mod;
                tmp[j+s][1] += dp[n][j][1]*(dp[to][s][0])%mod;
                tmp[j+s][1] %= mod;
                tmp[j+s][2] += dp[n][j][2]*(dp[to][s][0] + dp[to][s][2])%mod;
                tmp[j+s][2] %= mod;
            }
        }
        sz[n] = min(x, sz[n] + sz[to]);
        for(int j = 0; j <= sz[n]; j++){
            for(int s = 0; s < 3; s++){
                dp[n][j][s] = tmp[j][s];
            }
        }

    }
}
int main()
{
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n - 1; i ++){
        int s,t;
        scanf("%d%d", &s, &t);
        arcs[s].pb(t);
        arcs[t].pb(s);
    }
    scanf("%lld %d", &k, &x);
    dfs(1,0);
    ll ans = 0;
    for(int i = 0; i <= x; i++){
        for(int j = 0; j < 3; j++){
            ans += dp[1][i][j] % mod;
            ans %= mod;
        }
    }
    printf("%lld", ans);
    return 0;
}
