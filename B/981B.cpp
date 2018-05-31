#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 100005;
typedef pair<int,int> pii;
int n,m;
unordered_map<ll,ll> income;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i ++){
        ll idx, inc;
        cin >> idx >> inc;
        income[idx] = inc;
    }
    cin >> m;
    for(int j = 0; j < m; j ++){
        ll idx, inc;
        cin >> idx >> inc;
        income[idx] = max(income[idx], inc);
    }
    ll ans = 0;
    for(auto pr: income){
        ans += pr.second;
    }
    cout<<ans<<endl;
    return 0;
}