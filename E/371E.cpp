#include "bits/stdc++.h"
using namespace std;
typedef long long int LL;
typedef pair<LL,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
const int N= 300005;
int n,k;
pii x[N];
LL sum[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> x[i].first;
        x[i].second = i;
    }
    sort(x + 1, x + 1 + n);
    cin >> k;
    for(int i = 1; i <= n; i ++)
        sum[i] = sum[i-1] + x[i].first;
    LL minval = 0;
    LL cur = 0;
    int mink = k;
    for(int i = k + 1; i <= n; i ++){
        LL update = (k-1) * (x[i].first + x[i-k].first) - 2 * (sum[i-1] - sum[i-k]);
        cur += update;
        if(cur < minval){
            minval = cur;
            mink = i;
        }
    }
    for(int l = mink - k + 1; l <= mink; l ++)
        cout<<x[l].second<<" ";
    return 0;
}