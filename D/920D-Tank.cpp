#include <map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 5010;
ll N, K, V;
ll a[maxn];
bool dp[maxn][maxn];
int path[maxn][maxn];
vector<int> s;
vector<int> r;
ll sum;
bool work(){
    ll remainder = V % K;
    dp[0][a[0] % K] = true;
    dp[0][0] = true;
    path[0][0] = -1;
    for(int i = 1; i < N; i++){
        for(int j = 0; j < K; j++){
            if(dp[i-1][j]){
                dp[i][j] = true;
                path[i][j] = -1;
                continue;
            }
            ll last = (j - a[i]) % K;
            if(last < 0)
                last += K;
            if(dp[i-1][last]){
                dp[i][j] = true;
                path[i][j] = last;
            }
        }
    }
    if(!dp[N-1][remainder] )
        return false;
    for(int i = N - 1; i >= 0; i--){
        if(path[i][remainder] == -1){
            r.push_back(i);
            continue;
        }
        else{
            remainder = path[i][remainder];
            sum += a[i];
            s.push_back(i);
        }
    }
    return true;
}
int main(){
    scanf("%lld%lld%lld", &N, &K, &V);
    ll ssum = 0;
    for(int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
        ssum += a[i];
    }
    if(ssum < V){
        printf("NO");
        return 0;
    }
    if(!work())
    {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(int i = 1; i < s.size(); i++){
        if(a[s[i]])
            printf("%lld %d %d\n", (K-1+a[s[i]])/K, 1 + s[i], 1 + s[0]);
    }
    for(int i = 1; i < r.size(); i++){
        if(a[r[i]])
            printf("%lld %d %d\n", (K-1+a[r[i]])/K, 1 + r[i], 1 + r[0]);
    }
    if(s.size() == 0 && 0 != V){
        printf("%lld %d %d\n", V/K, 1 + r[0], 1 + r[1]);
        return 0;
    }
    if(r.size() == 0 && sum != V){
        printf("%lld %d %d\n", (sum - V)/K, 1 + s[0], 1 + s[1]);
        return 0;
    }
    if(sum > V)
        printf("%lld %d %d\n", (sum - V)/K, 1 + s[0], 1 + r[0]);
    else if(sum < V)
        printf("%lld %d %d\n", (V - sum)/K, 1 + r[0], 1 + s[0]);
    return 0;
}