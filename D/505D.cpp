#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <iostream>
typedef long long ll;

using namespace std;

const int maxn = 100100;
int n,m;
vector<int> arc[maxn], meta[maxn];
stack<int> stk;
int ind, ans;
int dis[maxn], low[maxn];
bool vs[maxn];
int T;
int sccid[maxn];
int cycle[maxn];
void tarjan(int u){
    vs[u] = true;
    dis[u] = low[u] = T++;
    stk.push(u);
    for(int i = 0; i < arc[u].size(); i++){
        int v = arc[u][i];
        if(dis[v] == -1){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(vs[v])
            low[u] = min(low[u], dis[v]);
    }
    if(low[u] == dis[u]){
        int scc = 0;
        while(1){
            int v = stk.top();
            stk.pop();
            scc++;
            vs[v] = false;
            sccid[v] = ind;
            if(v == u) break;
        }
        if(scc != 1){
            cycle[ind] = 1;
        }
        ind ++;
    }
}
bool cycles = false;
int dfs(int s){
    vs[s] = true;
    int sum = 1;
    if(cycle[sccid[s]] == 1)
        cycles = true;
    for(int i = 0; i < meta[s].size(); i++){
        int j = meta[s][i];
        if(!vs[j]) sum += dfs(j);
    }
    return sum;
}
int main()
{
    scanf("%d %d",&n, &m);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        arc[a].push_back(b);
        meta[a].push_back(b);
        meta[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        dis[i] = -1;
    }
    for(int i = 1; i <= n; i++)
        if(dis[i] == -1)tarjan(i);


    for(int i = 1; i <= n; i++){
        if(!vs[i]) {
            cycles = false, ans += (dfs(i)-1);
            if (cycles)
                ans++;
        }
    }
    printf("%d",ans);
    return 0;
}