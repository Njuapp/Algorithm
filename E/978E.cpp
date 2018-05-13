#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
const int maxn = 100000;
typedef long long int ll;
typedef pair<int,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
int n;
ll w;
int main(){
    cin >> n >> w;
    ll maxi = 0, mini = 0;
    ll cur = 0;
    forn(i, n) {
        ll temp;
        scanf("%lld", &temp);
        cur += temp;
        maxi = max(cur, maxi);
        mini = min(cur, mini);
    }
    if(w < maxi - mini)
        cout<<0<<endl;
    else
        cout<<w-(maxi -mini) + 1<<endl;
    return 0;
}