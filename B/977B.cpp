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
string s;
unordered_map<string, int> mp;
int main() {
    cin >> n >> s;
    for(int i = 0; i < n - 1; i++){
        string sub = s.substr(i, 2);
        mp[sub]++;
    }
    int maxx = 0;
    string ans;
    for(auto it = mp.begin(); it!= mp.end(); it++){
        if(it->second > maxx){
            maxx = it->second;
            ans = it->first;
        }
    }
    cout<<ans;
    return 0;
}