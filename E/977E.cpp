#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long int ll;
int n, m;
vector<int> graph[200010];
int v[200010];
void dfss(int now){
    v[now] = 1;
    for(auto idx: graph[now]){
        if(!v[idx])
            dfss(idx);
    }
}
bool dfs(int now){
    if(graph[now].size() != 2) {
        dfss(now);
        return false;
    }
    vector<int> all;
    all.push_back(now);
    int next = graph[now][0];
    int prev = now;
    bool flag = true;
    while(next != now){
        all.push_back(next);
        if(graph[next].size() != 2){
            flag = false;
            break;
        }
        int tmp = next;
        next = graph[tmp][0];
        if(next == prev)
            next = graph[tmp][1];
        prev = tmp;
    }
    if(!flag)
        dfss(now);
    else{
        for(auto idx: all)
            v[idx] = 1;
    }
    return flag;
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int s, t;
        scanf("%d %d", &s, &t);
        graph[s].push_back(t);
        graph[t].push_back(s);
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        if(!v[i] && dfs(i))
            ans++;
    }
    cout << ans;
    return 0;
}