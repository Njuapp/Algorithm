#include <iostream>
#include <utility>
#include <set>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
#define rep(i,n) for(int i = 0; i < (n); i ++)
int n;
int a[2010];
int dp[2010][4];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    rep(i, n){
        cin >> a[i+1];
    }
    for(int i = 1; i <= n; i ++){
        if(a[i] == 1)
            dp[i][0] = dp[i-1][0] + 1;
        else
            dp[i][0] = dp[i-1][0];
        if(a[i] == 1)
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + 1);
        else
            dp[i][1] = max(dp[i-1][1] + 1, dp[i-1][0] + 1);
        if(a[i] == 1)
            dp[i][2] = max(dp[i-1][2] + 1, dp[i-1][1] + 1);
        else
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + 1);
        if(a[i] == 1)
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] + 1);
        else
            dp[i][3] = max(dp[i-1][3] + 1, dp[i-1][2] + 1);
        
    }
    cout<<dp[n][3]<<endl;
    return 0;
}