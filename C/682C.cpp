#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll n;
ll arr[100010];
ll p[100010];
vector<int> graph[100010];
ll cost[100010];
ll maxima[100010];
int sum = 0;
void dfs(int start){
    sum ++;
    if(maxima[p[start]] >= 0)
        maxima[start] = cost[start] + maxima[p[start]];
    else
        maxima[start] = cost[start];
    for(auto child: graph[start]){
        dfs(child);
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> arr[i];
    for(int i = 2; i <= n; i ++){
        cin >> p[i] >> cost[i];
        graph[p[i]].push_back(i);
    }
    dfs(1);
    for(int i = 0; i < 100010; i ++)
        graph[i].clear();
    for(int i = 1; i <= n; i ++){
        if(maxima[i] <= arr[i])
            graph[p[i]].push_back(i);
    }
    sum = 0;
    dfs(1);
    cout << n - sum << endl;
    return 0;
}