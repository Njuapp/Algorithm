#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <queue>
#include <cmath>
#include <bitset>
using namespace std;
const int maxn = 200010;
typedef long long int ll;
typedef pair<ll,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
string name[3]={"Kuro","Shiro","Katie"};
string rib[3]={"","",""};

int main(){
    ll n;
    cin >> n;
    for(int i = 0; i < 3; i++)
        cin >> rib[i];
    vector<ll> cnt(3,0);
    int idx = -1;
    for(int i = 0;i < 3; i++){
        vector<int> chars(256,0);
        int maxoc = 0;
        for(int j = 0; j < rib[i].length();j++){
            chars[rib[i][j]] ++;
            maxoc = max(maxoc, chars[rib[i][j]]);
        }
        int rem = rib[i].length() - maxoc;
        if(n <= rem){
            cnt[i] = maxoc + n;
            continue;
        }
        if(n == 1){
            cnt[i] = rib[i].length() - 1;
        }
        else
            cnt[i] = rib[i].length();
    }
    idx = 0;
    ll maxi = cnt[0];
    for(int i = 1; i < 3; i ++){
        if(cnt[i] > maxi){
            idx = i;
            maxi = cnt[i];
        }
    }
    for(int i = 0; i < 3; i++){
        if(i != idx && maxi == cnt[i]){
            cout<<"Draw";
            return 0;
        }
    }
    cout<<name[idx];
    return 0;
}