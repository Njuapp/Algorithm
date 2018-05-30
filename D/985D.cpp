#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 100005;
typedef pair<int,int> pii;
ll n, H;
bool valid(ll k ){
    ll h1 = min(k, H);
    ll cnt = k * k - h1 * (h1 - 1)/ 2;
    return cnt <= n;
}
ll binsearch(){
   ll lo = 1, hi = 2e9;
   while(lo < hi){
       ll mid = (lo + hi) / 2;
       if(valid(mid))
           lo = mid + 1;
       else
           hi = mid;
   }
   return hi -1 ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> H;
    ll k = binsearch();
    ll ans = 2 * k - 1 - min(k, H) + 1;
    ans += (n - k * k + min(k,H) *(min(k,H)-1)/2) / k;
    if((n - k * k + min(k,H) *(min(k,H)-1)/2) % k)
        ans++;
    cout<<ans<<endl;
    return 0;
}