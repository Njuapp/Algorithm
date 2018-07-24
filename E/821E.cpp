#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pll;
typedef vector<LL> vec;
typedef vector<vec> mat;
const LL mod = 1e9 + 7;
mat mul(mat A, mat B){
    mat res(A.size(), vec(B[0].size()));
    for(int i = 0; i < res.size(); i ++){
        for(int j = 0; j < res[i].size(); j ++){
            for(int k = 0; k < A[i].size(); k ++){
                res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return res;
}

mat trans(int h){
    mat res(h, vec(h));
    for(int i = 0; i < h; i ++){
        res[i][i] = 1;
        if(i - 1 >= 0)
            res[i][i-1] = 1;
        if(i + 1 < h)
            res[i][i+1] = 1;
    }
    return res;
}

mat quickpow(mat X, LL times){
    mat res(X.size(), vec(X.size()));
    for(int i = 0; i < X.size(); i ++)
        res[i][i] = 1;
    while(times != 0){
        if(times & 1)
            res = mul(res, X);
        X = mul(X, X);
        times >>= 1;
    }
    return res;
}

int n;
LL k;
pll seg[100];
int c[100];
int dp[2][16];
int u;

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    for(int i = 0; i < n; i ++){
        cin >> seg[i].first >> seg[i].second >> c[i];
    }
    dp[0][0] = 1;
    for(int i = 0; i < n; i ++){
        u ^= 1;
        mat tran = trans(c[i] + 1);
        tran = quickpow(tran, min(seg[i].second, k) - seg[i].first);
        memset(dp[u], 0, sizeof(dp[u]));
        for(int j = 0; j <= c[i]; j ++){
            for(int k = 0; k <= c[i]; k ++){
                dp[u][j] = (dp[u][j] + dp[u^1][k] * tran[j][k]) % mod;
            }
        }
    }
    cout<<dp[u][0]<<endl;
    return 0;
}
