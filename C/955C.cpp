#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const ll maxn = 1e18;
typedef pair<int,int> pii;
int q;
vector<ll> ans;
ll K(ll num){
    if(!num)return 0;
    ll sqr = (int)sqrt(num);
    sqr += upper_bound(ans.begin(), ans.end(), num) - ans.begin();
    return sqr;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i = 2; i <= 1e6; i ++){
        ll ret = i;
        while(ret <= 1e18 && log10(ret) + log10(i) <= 18){
            ret *= i;
            ll sqr = sqrt(ret);
            if(sqr * sqr != ret) ans.push_back(ret);
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cin >> q;
    while(q--){
        ll l,r;
        cin >> l >> r;
        cout << K(r) - K(l-1) ;
        cout << endl;
    }
    return 0;
}