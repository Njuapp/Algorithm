#include <bits/stdc++.h>
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
using namespace std;
typedef long long int ll;
const int maxn = 5010;
int n;
int a[maxn];
int q;
int dp[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        dp[0][i] = a[i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j + i < n; j ++){
            dp[i][j] = dp[i-1][j] ^ dp[i-1][j+1];
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j + i < n; j ++){
            dp[i][j] = max( max(dp[i][j], dp[i-1][j]), dp[i-1][j+1]);
        }
    }
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        l--;
        int len = r - l - 1;
        cout<<dp[len][l]<<endl;
    }
    return 0;
}