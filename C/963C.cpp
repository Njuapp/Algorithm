#include <iostream>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn = 2e5+10;
int n;
ll w[maxn], h[maxn], c[maxn];
map<ll,int> mp;
map<ll,bool> mb;
ll Gcd(ll x, ll y){
    return !y? x: Gcd(y, x%y);
}
ll g;
ll cnt;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> w[i] >> h[i] >> c[i];
        g=Gcd(g, c[i]);
    }
    if(g == 1){
        cout<<0<<endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(!mb[w[i]]) cnt++, mb[w[i]]=true;
        mp[h[i]]++;
    }
    for(auto v:mp){
        if(v.second != cnt){
            cout<<0<<endl;
            return 0;
        }
    }
    int ans = 0, sq = sqrt(g);
    for(int i = 1; i <= sq; i++){
        if(!(g%i)){
            ans++;
            if(i * i != g)
                ans++;
        }

    }
    cout<<ans<<endl;
    return 0;
}