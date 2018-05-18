#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 100010;
typedef pair<int,int> pii;
int n;
vector<int> g[maxn];
bitset<maxn> v;
int sum = 0;
int dfs(int s){
    v[s] = true;
    int nodes = 1;
    for(auto next: g[s]){
        if(!v[next])
            nodes += dfs(next);
    }
    if(nodes % 2 == 0)
        sum++;
    return nodes;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n % 2){
        cout<<-1;
        return 0;
    }
    dfs(1);
    cout<<sum-1;
    return 0;
}