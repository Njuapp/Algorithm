#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 100005;
typedef pair<int,int> pii;
int n,m,k,s;
int a[maxn];
vector<int> g[maxn];
int ans[maxn][105];
void bfs(int p){

    queue<int> q;
    for(int i = 1; i <= n; i ++) if(ans[i][p] == 0) q.push(i);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for(int next: g[k])
        {
            if(ans[next][p] > ans[k][p] + 1){
                ans[next][p] = ans[k][p] + 1;
                q.push(next);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k >> s;
    forn(i,n){
        cin >> a[i+1];
    }
    while(m--){
        int so,to;
        cin >> so >> to;
        g[so].push_back(to);
        g[to].push_back(so);
    }
    memset(ans, 0x3F, sizeof(ans));
    for(int i = 1; i <= k; i ++) 
      for(int j = 1; j <= n; j ++) 
        if(a[j] == i) ans[j][i] = 0;
    for(int i = 1; i <=k ; i ++) 
      bfs(i);
    for(int i = 1; i <= n; i++) 
      sort(ans[i] + 1, ans[i] + 1 + k);
    for(int i = 1; i <= n; i++) 
      cout<<accumulate(ans[i] + 1, ans[i] + 1 + s, 0)<<" ";
    return 0;
}