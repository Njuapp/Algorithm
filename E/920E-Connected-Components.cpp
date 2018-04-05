//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-13 00:47:09
//Last modified: 2018-02-13 14:37:44
#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
set<int> unvisited;
int n, m;
set<int> mp[200001];
bool to(int s, int e){
    if(s==e)
        return false;
    if(mp[s].find(e)!=mp[s].end())
        return false;
    else
        return true;
}
int dfs(int s){
    unvisited.erase(s);
    int sum = 1;
    int p = s;
    while(1){
        auto it = unvisited.upper_bound(p);
        if(it==unvisited.end())
            break;
        p = *it;
        if(to(s,p) ){
            sum += dfs(p);
        }
    }
    return sum;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        unvisited.insert(i+1);
    bool debug = false;
    if(m == 200000)
        debug = true;
    while(m--){
        int a,b;
        cin >> a>>b;
        mp[a].insert(b);
        mp[b].insert(a);
    }
    int sum = 0;
    vector<int> res;
    for(int i = 1; i <=n ;i++){
        if(unvisited.find(i) != unvisited.end()){
            sum++;
            res.push_back(dfs(i));
        }
    }
    cout<<sum<<endl;
    sort(res.begin(),res.end());
    for(int e:res)cout<<e<<" ";
    cout<<endl;
    return 0;
}

