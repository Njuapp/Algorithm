/*
 * Author: Cheng Hang on 04/10/2018
 * All Copyrights Reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
using namespace std;
typedef long long int ll;
typedef pair<ll,int> P;
#define MAX 200010
vector<P> G[MAX];
ll dist[MAX];
set<P> s;
using namespace std;
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    while(m--){
        int s,j;
        ll w;
        scanf("%d %d %lld", &s, &j, &w);
        G[s].push_back(make_pair(2*w,j));
        G[j].push_back(make_pair(2*w,s));
    }
    for(int i = 1; i <= n; i++){
        ll p;
        scanf("%lld", &p);
        G[0].push_back(make_pair(p, i));
        dist[i] = p + 1;
    }
    dist[0] = 0;
    s.insert(P(0,0));
    while(s.size()){
        auto node = *s.begin();
        s.erase(s.begin());
        for(auto e: G[node.second]){
            if(dist[e.second] > dist[node.second] + e.first){
                s.erase(P(dist[e.second], e.second));
                dist[e.second] = e.first + dist[node.second];
                s.insert(P(dist[e.second], e.second));
            }
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%lld ", dist[i]);
    return 0;
}