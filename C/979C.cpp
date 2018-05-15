#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <queue>
#include <cmath>
#include <bitset>
using namespace std;
const int maxn = 300010;
typedef long long int ll;
typedef pair<int,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
ll n;
int x,y;
vector<int> g[maxn];
ll s[maxn];
bool v[maxn];
bool chk_sub[maxn];
void dfs(int u){
    s[u] = 1;
    v[u] = true;
    if(u == x){
        chk_sub[u] = true;
    }
    for(auto child: g[u]){
        if(!v[child]){
            dfs(child);
            s[u] += s[child];
            chk_sub[u] |= chk_sub[child];
        }
    }
}
int main(){
    cin >> n >> x >> y;
    for(int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(y);
    for(int k: g[y]){
        if(chk_sub[k]){
            s[y] -= s[k];
            break;
        }
    }
    cout<<(n-1) * n - s[x]*s[y];
    return 0;
}