#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long int ll;
int n;
ll arr[100];
unordered_map<ll, int> mp;
vector<int> graph[100];
int indegree[100];
int v[100];
int main() {
    cin >> n ;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]] = i;
    }
    for(int i = 0;i < n; i++){
        if(mp.find(arr[i] * 2) != mp.end()) {
            graph[i].push_back(mp[arr[i] * 2]);
            indegree[mp[arr[i] * 2]]++;
        }
        if(arr[i]%3 == 0 && mp.find(arr[i] / 3) != mp.end()) {
            graph[i].push_back(mp[arr[i] / 3]);
            indegree[mp[arr[i] / 3]]++;
        }

    }
    for(int i = 0; i < n; i++){
        int ind = -1;
        for(int j = 0; j < n; j++){
            if(!v[j] && indegree[j] == 0){
                ind = j;
                v[j] = 1;
                break;
            }
        }
        cout << arr[ind]<<" ";
        for(auto k : graph[ind])
            indegree[k] --;
    }
    return 0;
}