#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 3000;
typedef pair<ll,int> pii;
int n;
ll s[maxn], c[maxn], cc[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    forn(i,n){
        cin >> s[i];
    }
    forn(i,n){
        cin >> c[i];
        cc[i] = 1e9;
    }
    forn(i,n){
        forn(j,i){
            if(s[j] < s[i]) cc[i] = min(cc[i], c[i] + c[j]);
        }
    }
    ll ans = 1e9;
    forn(i,n){
        forn(j,i){
            if(s[j] < s[i]) ans = min(ans, c[i] + cc[j]);
        }
    }
    if(ans == 1e9)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}