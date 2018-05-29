#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const ll maxn = 1e18;
typedef pair<int,int> pii;
int mp[2000][2000];
int cnt[2000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            char ch;
            cin >> ch;
            if(ch == '0')
                mp[i][j] = 0;
            else {
                mp[i][j] = 1;
                cnt[j] ++;
            }
        }
    }
    for(int i = 0; i < n; i ++){
        bool flag = true;
        for(int j = 0; j < m; j ++){
            if(mp[i][j]){
                if(cnt[j] == 1){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}