#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 100005;
typedef pair<int,int> pii;
string str;
int dp[55][55];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> str;
    for(int i = 0; i < str.length(); i++) {
        dp[i][i] = 1;
        if (i >= 1) dp[i][i - 1] = 1;
    }
    int maxi = 0;

    for(int len = 2; len <= str.length(); len++){
        for(int s = 0; s + len - 1 < str.length(); s++){
            int e = s + len - 1;
            if(str[s] == str[e] && dp[s+1][e-1]) {
                dp[s][e] = 1;
            }else{
                maxi = max(maxi, len);
            }
        }
    }
    cout<<maxi<<endl;
    return 0;
}