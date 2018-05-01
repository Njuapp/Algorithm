#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long int ll;
struct node{
    ll h;
    ll d;
    ll inc;
};
typedef pair<ll, ll > pll;
int n, a, b;
const int maxn = 200010;
node arr[maxn];
bool cmp(node a, node b){
    return a.inc > b.inc;
}
int main() {
    cin >> n >> a >> b;
    ll s = 0, ans = 0, t = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].h >> arr[i].d;
        arr[i].inc = max(0ll, arr[i].h - arr[i].d);
        s += arr[i].d;
    }
    sort(arr, arr + n, cmp);
    for(int i = 0; i < b; i++)
        t += arr[i].inc;
    for(int i = 0; i < b; i++){
        ll inc = arr[i].h << a;
        ans = max(ans, t - arr[i].inc + inc - arr[i].d);
    }
    for(int i = b; i < n; i++){
        ll inc = arr[i].h << a;
        ans = max(ans, t - arr[b-1].inc + inc - arr[i].d);
    }
    if(!b)
        ans = 0;
    cout<< ans + s << endl;

    return 0;
}