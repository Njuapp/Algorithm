#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long int ll;
int n, q;
const int maxn = 200010;
ll life[maxn];
ll arrow[maxn];
int start;
int binsearch(ll attack){
    int lo = start;
    int hi = n - 1;
    while(lo < hi){
        int mid = (lo + hi ) / 2;
        if(life[mid] < attack)
            lo = mid + 1;
        else if(life[mid] == attack)
            return mid + 1;
        else
            hi = mid;
    }
    return life[hi] > attack ? hi: n;
}
int main() {
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &life[i]);
        life[i] += ((i == 0) ? 0: life[i-1]);
    }
    for(int i = 0; i < q; i++) {
        scanf("%lld", &arrow[i]);
        arrow[i] += ((i == 0) ? 0 : arrow[i - 1]);
    }
    ll prev = 0;
    for(int i = 0; i < q; i ++){
        int alive = binsearch(arrow[i] - prev);
        if(alive != n)
            printf("%d\n", n - alive);
        else {
            printf("%d\n", n);
            prev = arrow[i];
        }
    }
    return 0;
}