#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <queue>
#include <bitset>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
vector<int> mp[100010];
int nodd = 0;
bitset<100010> v;
void bfs(){
    queue<pii> q;
    q.push(make_pair(1,0));
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        v[now.first] = true;
        if(now.second % 2 ){
            nodd++;
        }
        for(auto k: mp[now.first]){
            if(!v[k])
                q.push(make_pair(k, now.second+1));
        }
    }
}
int n;
int main() {
    cin >> n;
    for(int i = 1; i < n; i ++){
        int s,t;
        cin >> s >> t;
        mp[s].push_back(t);
        mp[t].push_back(s);
    }
    bfs();
    cout<< (n - nodd) * nodd - (n - 1);
    return 0;
}