#include <iostream>
#include <utility>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
#define rep(i,n) for(int i = 0; i < (n); i ++)
int n,m;
string s;
vector<int> g[300001];
int indegree[300001];
int dp[300001][26];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> s;
    while(m--){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(indegree[i] == 0){
            q.push(i);
            dp[i][s[i-1] - 'a'] = 1;
            cnt ++;
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int k = 0; k < g[node].size(); k ++){
            int end = g[node][k];
            for(int i = 0; i < 26; i ++){
                dp[end][i] = max(dp[end][i], dp[node][i]);
            }
            indegree[end]--;
            if(indegree[end] == 0){
                q.push(end);
                dp[end][s[end-1] - 'a'] ++;
                cnt ++;
            }
        }
    }
    if(cnt != n){
        cout<<-1<<endl;
        return 0;
    }
    int maxv = 0;
    for(int node = 1; node <= n; node ++){
        for(int j = 0; j < 26; j ++){
            maxv = max(maxv, dp[node][j]);
        }
    }
    cout<<maxv<<endl;
    return 0;
}
