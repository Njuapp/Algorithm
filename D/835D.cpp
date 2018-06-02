#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 200005;
typedef pair<int,int> pii;
string s;
int ans[5005];
int palin[5005][5005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    int n = s.length();
    for(int i = 1; i <= n; i++){
        palin[i][i] = 1;
    }
    for(int i = 2; i <= n; i++){
        if(s[i-1] == s[i-2])
            palin[i-1][i] = 1;
    }
    for(int len = 3; len <= n; len++){
        for(int i = 0; i + len - 1 < n; i++){
            if(s[i] == s[i+len-1] && palin[i+2][i+len-1])
                palin[i+1][i+len] = 1;
        }
    }
    for(int len = 1; len <= n; len++){
        for(int i = 1; i + len - 1 <= n; i ++){
            int k = 1;
            int length = len;
            while(length >= 1 &&palin[i][i+length-1]){
                ans[k] ++;
                length /= 2;
                k++;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}