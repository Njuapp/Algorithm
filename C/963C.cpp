#include <iostream>
#include <utility>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
const LL MOD = 1e9+9;
#define rep(i,n) for(int i = 0; i < (n); i ++)
LL n, a, b, k;
int s[100005];
LL quickpow(LL n, LL p){
    if(p == 0)
        return 1;
    LL res = quickpow(n, p >> 1);
    if(p & 1)
        return ((res * res) % MOD) * n % MOD;
    else
        return (res * res) % MOD;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str;
    cin >> n >> a >> b >> k >> str;
    for(int i = 0; i < k; i ++){
        if(str[i] == '+')
            s[i] = 1;
        else
            s[i] = -1;
    }
    LL Z = 0;
    for(int i = 0; i < k; i ++){
        Z = (Z + (s[i] * quickpow(a, n - i) * quickpow(b, i)) % MOD) % MOD;
    }
    LL q = b * quickpow(a, MOD - 2) % MOD;
    q= quickpow(q, k);
    LL sum = 0;
    LL num = (n+1)/k;
    if(q == 1){
        sum = Z * num % MOD;
    }
    else{
        sum = (Z * (quickpow(q, num) - 1) % MOD * quickpow(q - 1, MOD - 2) + MOD) % MOD;
    }
    cout << (sum + MOD) % MOD<< endl;
    return 0;
}
