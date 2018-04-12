//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-18 10:27:37
//Last modified: 2018-02-18 23:43:49
#include <iostream>
#include <vector>
#include <cstdio>
const int maxn = 400000+10;
using namespace std;
typedef long long int ll;
ll w[maxn];
ll par[maxn][20];
ll par_sum[maxn][20];
int cnt = 1;
int main()
{
    int Q;
    cin >> Q;
    ll last = 0;
    w[0] = LLONG_MAX;
    for(int i=0;i<20;i++)par_sum[1][i]=LLONG_MAX;
    while(Q--){
        int type;
        ll p, q;
        scanf("%d %lld %lld", &type, &p, &q);
        p ^= last;
        q ^= last;
        if(type == 1){
            w[++cnt] = q;
            if(w[p] >= w[cnt])
                par[cnt][0] = p;
            else{

                for(int i = 19; i >= 0; i--){
                    if(w[par[p][i]] < w[cnt])
                        p = par[p][i];
                }
                par[cnt][0] = par[p][0];
            }
            par_sum[cnt][0] = (par[cnt][0] == 0)?LLONG_MAX:w[par[cnt][0]];
            for(int i = 1; i <= 19; i++){
                par[cnt][i] = par[par[cnt][i-1]][i-1];
                if(par[cnt][i] == 0)
                    par_sum[cnt][i] = LLONG_MAX;
                else
                    par_sum[cnt][i] = par_sum[cnt][i-1] + par_sum[par[cnt][i-1]][i-1];
            }
        }
        else{
            if(w[p] > q){
                cout<<0<<endl;
                last = 0;
                continue;
            }
            last = 1;
            q -= w[p];
            for(int i = 19; i >= 0; i--){
                if(q >= par_sum[p][i]){
                    q -= par_sum[p][i];
                    last += (1 << i);
                    p = par[p][i];
                }
            }
            printf("%lld\n",last);
        }
    }
    return 0;
}
