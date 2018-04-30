#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long int ll;
ll n, m, k;
int main() {
    cin >> n >> m >> k;
    if( k < n){
        cout << k + 1 <<" "<<1<<endl;
        return 0;
    }
    k -= (n);
    ll remain = k %(2 * (m-1));
    ll line = k / (2 *(m-1));
    if(remain >= 0 && remain < (m-1))
        cout<< n - 2* line <<" "<<2 + remain<<endl;
    else
        cout<< n - 1 - 2 * line << " "<< m  - (remain - (m-1))<<endl;
    return 0;
}