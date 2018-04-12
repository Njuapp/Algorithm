//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-13 00:47:09
//Last modified: 2018-04-12 13:50:18
#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>

using namespace std;
bitset<200010> unvisited;
int n, m;
int k;
int res[200010];
unordered_map<int,bool> mp[200010];
bool to(int s, int e){
    if(s==e)
        return false;
    if(mp[s].find(e)!=mp[s].end())
        return false;
    else
        return true;
}
void dfs(int s){
    unvisited[s] = 0;
    res[k] ++;
    for(auto i= unvisited._Find_first(); i < unvisited.size(); i = unvisited._Find_next(i)){
        if(!mp[s][i])
            dfs(i);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        unvisited[i] =1;
    while(m--){
        int a,b;
        cin >> a>>b;
        mp[a][b] = true;
        mp[b][a] = true;
    }
    for(int i = 1; i <=n ;i++){
        if(unvisited[i]) {
            dfs(i);
            k++;
        }
    }
    cout<<k<<endl;
    sort(res,res+k);
    for(int i = 0; i < k ; i++)
        cout<< res[i]<<" ";
    cout<<endl;
    return 0;
}

