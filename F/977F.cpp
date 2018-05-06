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
ll arr[200010];
int last[200010];
int maxlen[200010];
int out[200010];
unordered_map<ll , int> mp;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    int maxx = 0;
    int p = 0;
    for(int i = 1; i <= n; i++){
        if(mp.find(arr[i]-1) != mp.end()){
            int idx= mp[arr[i]-1];
            maxlen[i] = maxlen[idx] + 1;
            last[i] = idx;
        }
        else{
            last[i] = 0;
            maxlen[i] = 1;
        }
        if(maxlen[i] > maxx){
            maxx = maxlen[i];
            p = i;
        }
        mp[arr[i]] = i;
    }
    cout << maxx<<endl;
    int k = 0;
    for(int s = p; s != 0; s = last[s]){
        out[k++] = s;
    }
    for(int l = 0; l < k; l ++)
        cout << out[k-1-l]<< " ";
    return 0;
}