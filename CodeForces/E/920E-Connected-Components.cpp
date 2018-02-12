//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-13 00:47:09
//Last modified: 2018-02-13 01:43:20
#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
using namespace std;
map<int,bool> mp[200001];
int n, m;
int visited[200001];
bool to(int s, int e){
    if(s==e)
        return false;
    if(mp[s][e])
        return false;
    else
        return true;
}
int dfs(int s){
    visited[s] =1;
    int sum = 1;
    for(int i= 1; i <= n ; i++){
        if(to(s,i) && !visited[i]){
            sum += dfs(i);
        }
    }
    return sum;
}
int main(){
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a>>b;
        mp[a][b]=mp[b][a]=true;
    }
    int sum = 0;
    vector<int> res;
    for(int i = 1; i <=n ;i++){
        if(!visited[i]){
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

