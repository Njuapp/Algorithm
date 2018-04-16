#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 500+10;
int n, m , k;
string table[maxn];
int mini[maxn][maxn];
int dp[maxn][maxn];
int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n ; i++)
        cin >> table[i];
    for(int i = 0; i < n; i++){

        int sum = 0;
        for(int j = 0; j < m; j++)
            if(table[i][j] == '1')
                sum++;
        for(int j = 0; j < sum; j ++) {
            mini[i][j] = INT_MAX;//skip j classes on i-th day, solve the minimum hour required
        }
        int len = 0;
        for(int j = 0; j < m; j++){
            if(table[i][j] == '1')
                len ++;
            int tmplen = len;
            for(int s = 0; s <= j; s++){
                mini[i][sum - tmplen] = min(mini[i][sum - tmplen], j - s + 1);
                if(table[i][s] == '1')
                    tmplen--;
            }
        }
    }
    for(int j = 0; j <= k; j++)
        dp[0][j] = mini[0][j];
    for(int i = 1; i < n; i++){
        for(int j = 0; j  <= k ; j++){
            int ans = INT_MAX;
            for(int s = 0; s <= j; s++){
                ans = min(ans, mini[i][s] + dp[i-1][j-s]);
            }
            dp[i][j] = ans;
        }
    }
    cout<<dp[n-1][k]<<endl;
    return 0;
}