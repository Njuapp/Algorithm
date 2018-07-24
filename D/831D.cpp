#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pll;
#define rep(i,n) for(int i = 0; i < (n); i ++)
int n,k;
LL p;
LL a[1005];
LL b[2005];
LL dp[2005][1005];
LL cost(int i, int j){
    return abs(a[j] - b[i]) + abs(b[i] - p);
}
int main(int argc, const char * argv[]) {
    cin >> n >> k >> p;
    rep(i,n){
        cin >> a[i+1];
    }
    sort(a + 1, a + n + 1);
    rep(i,k){
        cin >> b[i+1];
    }
    sort(b + 1, b + k + 1);
    memset(dp, 0x3f, sizeof(dp));
    rep(i,k + 1){
        dp[i][0] = 0;
    }
    for(int i = 1; i <= k; i ++){
        for(int j = 1; j <= min(i, n); j ++){
            dp[i][j] = min(dp[i-1][j], max(dp[i-1][j-1], cost(i,j)));
        }
    }
    cout<<dp[k][n]<<endl;
    return 0;
}
