#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
const int maxn= 1005;
int n, m;
pii a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    forn(i, m)
        cin >> a[i].first >> a[i].second;
    forn(i,n){
        if(i%2)
            cout<<0;
        else
            cout<<1;
    }
    return 0;
}