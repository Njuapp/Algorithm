#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1000+5];
int n ;
int minDist(vector<int> dist, vector<bool> visited){
    int min_dist = INT_MAX;
    int idx = -1;
    for(int v = 1; v <= n; v++ ){
        if(!visited[v] && dist[v] < min_dist) {
            idx = v;
            min_dist = dist[v];
        }
    }
    return idx;
}
vector<int> dijsktra(int s){
    vector<int> dist(n+1,INT_MAX);
    vector<bool> visited(n+1, false);
    dist[s] = 0;
    for(int i = 0; i < n - 1; i++){
        int u = minDist(dist, visited);
        visited[u] = true;
        for(int v = 0; v < graph[u].size(); v++){
            int node = graph[u][v];
            dist[node] = min(dist[node], dist[u] + 1);
        }

    }
    return dist;
}
int main(){
    int  m, s, t;
    cin >>n >> m >> s >> t;
    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    vector<int> from_s = dijsktra(s);
    vector<int> from_t = dijsktra(t);
    int res = 0;
    for(int v = 1; v <= n; v++){
        vector<bool> shit(n+1,true);
        for(int k = 0; k < graph[v].size(); k++){
            shit[graph[v][k]] = false;
        }
        for(int i = v+1; i <= n; i++){
            if(shit[i]&& from_s[i] + from_t[v] + 1 >= from_s[t] && from_t[i] + from_s[v] + 1>= from_s[t]){
                res ++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}