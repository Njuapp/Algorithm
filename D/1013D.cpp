#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
#define rep(i,n) for(int i = 0; i < (n); i ++)
int n,m,q;
vector<int> graph[400001];
int v[400001];
void dfs(int i){
    v[i] = 1;
    for(int j : graph[i]){
        if(!v[j])
            dfs(j);
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> q;
    while(q--){
        int r,c;
        cin >> r >> c;
        graph[r].push_back(c+n);
        graph[c+n].push_back(r);
    }
    int ans = 0;
    for(int i = 1; i <= n+m; i ++){
        if(!v[i]){
            dfs(i);
            ans ++;
        }
    }
    cout<< ans - 1 <<endl;
    return 0;
}