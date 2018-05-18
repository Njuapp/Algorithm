#include <bits/stdc++.h>
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
using namespace std;
typedef long long int ll;
const int maxn = 5010;
int sch[105];
int n,s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        int h,m;
        cin >> h >> m;
        sch[i] = h * 60 + m;
    }
    for(int i = 1; i <= n + 1; i++){
        if(i == 1){
            if(sch[i] >= s + 1){
                cout<<0<<" "<<0;
                return 0;
            }
        }
        if( i == n + 1){
            cout << (sch[n] + 1 + s) / 60 <<" "<<(sch[n] + 1 + s)%60;
            return 0;
        }
        if(sch[i] - sch[i-1] >= 2 * s + 2){
            cout<< (sch[i-1] + 1 +s ) / 60 <<" "<<(sch[i-1] + 1 + s)%60;
            return 0;
        }
    }
    return 0;
}