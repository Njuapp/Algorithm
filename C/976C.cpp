#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
struct inter{
    pll ti;
    int idx;
};
int n;
const int maxn = 300010;
inter segs[maxn];
bool cmp(inter a, inter b){
    if(a.ti.first < b.ti.first)
        return true;
    if(a.ti.first > b.ti.first)
        return false;
    if(a.ti.second >= b.ti.second)
        return true;
    else
        return false;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%lld %lld",&segs[i].ti.first, &segs[i].ti.second);
        segs[i].idx = i;

    }
    sort(segs+1, segs+n+1,cmp);
    int cur = 1;
    for(int i = 2; i <= n; i++){
        if(segs[i].ti.second <= segs[cur].ti.second){
            cout<<  segs[i].idx << " "<<segs[cur].idx<< endl;
            return 0;
        }
        cur = i;
    }
    cout<<-1<<" "<<-1<<endl;
    return 0;
}