#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <iostream>

using namespace std;

const int N=100010;

vector <int> arc[N], scc[N], ans;
int n, m,h, ind, T;
int dfn[N], low[N], id[N], hour[N];
bool vs[N];
stack <int> s;

void tarjan(int u)
{
    s.push(u), vs[u]=1;
    dfn[u]=low[u]=T++;
    int len=(int)arc[u].size();
    for(int i=0; i<len; i++)
    {
        int v=arc[u][i];
        if(dfn[v]==-1)
        {
            tarjan(v);
            if(low[v]<low[u]) low[u]=low[v];
        }
        else if(vs[v] && low[u]>dfn[v]) low[u]=dfn[v];
    }
    if(low[u]==dfn[u])
    {
        for(int v; 1; )
        {
            v=s.top();
            s.pop(), vs[v]=0;
            id[v]=ind, scc[ind].push_back(v);
            if(v==u) break;
        }
        ind++;
    }
}

int main()
{
    scanf("%d%d%d", &n,&m, &h);
    for(int i = 1; i <= n; i++)
        scanf("%d",&hour[i]);
    for(int i=0, a, b; i<m; i++)
    {
        scanf("%d%d", &a, &b);
        if((hour[a]+1)%h == hour[b]) {
            arc[a].push_back(b);
        }
        if((hour[b]+1)%h == hour[a]){
            arc[b].push_back(a);
        }
    }
    for(int i=0; i<=n; i++) dfn[i]=-1, vs[i]=0, scc[i].clear();
    while(!s.empty()) s.pop();
    ind=T=0;
    for(int i=1; i<=n; i++) if(dfn[i]==-1) tarjan(i);
    for(int i=0; i<ind; i++) dfn[i]=0;
    for(int i=1; i<=n; i++)
    {
        int len=(int)arc[i].size(), u=id[i];
        for(int j=0; j<len; j++)
        {
            int v=id[arc[i][j]];
            if(v!=u) dfn[u]++;
        }
    }
    ans.clear();
    int idx = -1;
    int mini = INT_MAX;
    for(int i=0; i<ind; i++)
    {
        if(dfn[i]!=0) continue;
        if(scc[i].size() < mini){
            mini = scc[i].size();
            idx = i;
        }
    }
    printf("%lu\n", scc[idx].size());
    for(int i=0; i<scc[idx].size(); i++)
    {
        printf("%d ", scc[idx][i]);
    }
    return 0;
}