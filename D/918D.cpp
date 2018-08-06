#include <iostream>
#include <utility>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
#define rep(i,n) for(int i = 0; i < (n); i ++)
int n, m;
int w[105][105];
int dp[105][105][30];
int dfs(int i, int j, int prev){
    if(dp[i][j][prev]) return dp[i][j][prev];
    for(int k = 1; k <= n; k ++){
        if(k == i) continue;
        if(w[i][k] - 'a' >= prev && dfs(j, k, w[i][k] - 'a') == 2)
            return dp[i][j][w[i][k] - 'a'] = 1;
    }
    return dp[i][j][prev] = 2;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    while(m--){
        int u, v;
        string ww;
        cin >> u >> v >> ww;
        w[u][v] = ww[0];
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(dfs(i,j,0) == 1)cout<<'A';
            else cout<<'B';
        }
        cout<<endl;
    }
    return 0;
}
