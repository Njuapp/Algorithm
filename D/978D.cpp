#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
const int maxn = 100000;
typedef long long int ll;
typedef pair<int,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
int n;
ll b[100010];
ll a[100010];
int main(){
    cin >> n;
    forn(i,n)
        scanf("%lld", &b[i+1]);
    if(n==1 || n==2){
        cout<<0<<endl;
        return 0;
    }
    int ans = INT_MAX;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j ++){
            memcpy(a, b, sizeof(ll)*(n+1));
            a[1] = b[1] + i;
            a[2] = b[2] + j;

            ll cha = a[2] - a[1];
            int res = (i!=0) + (j!=0);
            bool flag = true;
            for(int k = 3; k <= n; k++){
                ll expe = a[k-1] + cha;
                if(abs(expe - a[k]) > 1){
                    flag = false;
                    break;
                }
                if(expe == a[k])
                    continue;
                else
                {
                    a[k] = expe;
                    res++;
                }
            }
            if(flag)
                ans = min(ans, res);
        }
    }
    if(ans == INT_MAX)
        ans = -1;
    cout<<ans<<endl;
    return 0;
}