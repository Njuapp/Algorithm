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
ll cost[maxn];
vector<int> arc[maxn];
stack<int> stk;
int ind;
int dis[maxn], low[maxn];
bool vs[maxn];
ll ans;
ll choices = 1;
int T;
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
        ll mini = LLONG_MAX;
        ll choice = 0;
        while(1){
            int v = stk.top();
            stk.pop();
            if(mini > cost[v]){
                mini = cost[v];
                choice = 1;
            }
            else if(mini == cost[v]){
                choice++;
            }
            vs[v] = false;
            if(v == u) break;
        }
        choices = (choices * choice) %1000000007;
        ans += mini;
        ind ++;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n ; i++)
        scanf("%lld", &cost[i]);
    scanf("%d", &m);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        arc[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        dis[i] = -1;
    }
    for(int i = 1; i <= n; i++)
        if(dis[i] == -1)tarjan(i);
    printf("%lld %lld", ans, choices);
    return 0;
}