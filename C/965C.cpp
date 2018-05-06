#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll n,k,M;
ll D;
int main() {
    scanf("%lld %lld %lld %lld", &n, &k, &M, &D);
    ll maxi = 0;
    for(ll d = 1; d <= D; d++){
        ll maxx = n / (1 + (d-1)* k);
        maxx = min(maxx, M);
        if(maxx == 0)
            break;
        ll reald = (n - maxx)/(k * maxx) + 1;
        if(reald != d)
            continue;
        maxi = max(maxi, d * maxx);
    }
    cout<<maxi<<endl;
    return 0;
}