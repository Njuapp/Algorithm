#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pll;
#define rep(i,n) for(int i = 0; i < (n); i ++)
string s;
int k;
const int N = 1000 + 5;
const int MOD = (int)1e9 + 7;
int F[N], Finv[N], inv[N];//F是阶乘，Finv是逆元的阶乘
void init(){
    inv[1] = 1;
    for(int i = 2; i < N; i ++){
        inv[i] = (MOD - MOD / i) * 1ll * inv[MOD % i] % MOD;
    }
    F[0] = Finv[0] = 1;
    for(int i = 1; i < N; i ++){
        F[i] = F[i-1] * 1ll * i % MOD;
        Finv[i] = Finv[i-1] * 1ll * inv[i] % MOD;
    }
}
int comb(int n, int m){//comb(n, m)就是C(n, m)
    if(m < 0 || m > n) return 0;
    return F[n] * 1ll * Finv[n - m] % MOD * Finv[m] % MOD;
}
bool valid(int num, int v){
    int ans = 0;
    while(num != 1){
        int tmp = num;
        num = 0;
        while(tmp){
            if(tmp & 1) num ++;
            tmp = tmp >> 1;
        }
        ans ++;
    }
    return ans == v;
}
int nums[1001];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s >> k;
    if(k == 0)
    {
        cout<<1<<endl;
        return 0;
    }
    else if(k == 1){
        cout<< s.length() - 1<<endl;
        return 0;
    }
    init();
    int ans = 0;
    int setbit = 0;
    for(int i = 0; i < s.length(); i ++)
        if(s[i] == '1') setbit++;
    for(int x = 1; x <= 1000; x ++){
        if(valid(x, k - 1)){
            int bits = x;
            for(int i = 0; i < s.length(); i ++){
                if(s[i] == '1'){
                    ans = (ans + comb((int)s.length() - 1 - i, bits)) % MOD;
                    bits--;
                }
            }
        }
    }
    cout<< ans + valid(setbit, k - 1)<< endl;
    return 0;
}
