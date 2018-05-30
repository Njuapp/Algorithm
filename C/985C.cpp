#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 100005;
typedef pair<int,int> pii;
int n,k;
ll l;
ll a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k >> l;
    int m = n * k;
    for(int i = 0; i < m; i ++)
        cin >> a[i];
    sort(a, a +m);
    auto num = upper_bound(a, a +m, a[0] + l) - a;
    //cout<< num ;
    if(num < n) {
        cout << 0;
        return 0;
    }
    ll ans = 0;
    int i,p;
    for(i = 0, p = 0; p <= num - 1 && n - i - 1 <= num - 1 - p; i++, p += k){
        ans += a[p];
    }
    for(int cnt = n - 1, idx = num-1; cnt >= i && idx >= 0; cnt--, idx--)
        ans += a[idx];
    cout<<ans<<endl;
    return 0;
}