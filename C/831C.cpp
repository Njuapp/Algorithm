#include <iostream>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
typedef long long int ll;
const int maxn = 2005;
int k,n;
ll a[maxn], b[maxn];
unordered_map<ll, int> zhou;
int main(){
    cin >> k >> n;
    for(int i = 1; i <= k; i++){
        cin >> a[i];
        a[i] += a[i-1];
        zhou[a[i]] ++;
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    unordered_set<ll> st;
    sort(b+1, b+n+1);
    for(int i = 1; i <= k; i++){
        ll init = b[1] - a[i];
        st.insert(init);
    }
    int ans = 0;
    for(auto candi: st){
        unordered_map<ll,int> mp = zhou;
        bool flag = true;
        for(int m = 1; m <= n; m++){
            if(mp[b[m] - candi] == 0){
                flag = false;
                break;
            }
            mp[b[m] - candi] --;
        }
        if(flag)
            ans++;
    }
    cout<< ans;
    return 0;
}