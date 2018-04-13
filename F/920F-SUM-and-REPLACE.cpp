//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-04-12 23:39:54
//Last modified: 2018-04-14 01:40:22
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1000*1000+10;
int val[maxn];
int d[maxn];
ll sum[maxn<<2];
int Max[maxn<<2];
void init(){
    for(int i = 1; i <= maxn; i++)
        for(int j = i ; j <= maxn; j+=i)
            d[j]++;
}
void push(int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    Max[rt] = max(Max[rt<<1] , Max[rt<<1|1]);
}
void build(int l, int r, int rt){
    if(l == r){
        sum[rt] = Max[rt] = val[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l , mid, rt << 1);
    build(mid + 1, r, rt << 1|1);
    push(rt);
}
void update(int rt, int ql , int qr, int l, int r){
    if(Max[rt]<=2)
        return;
    if(l == r){
        sum[rt] = Max[rt] = d[sum[rt]];
        return;
    }
    int mid = (l + r) >> 1;
    if(ql <= mid)
        update(rt << 1, ql, qr, l, mid);
    if(qr > mid)
        update(rt << 1|1, ql, qr, mid+1, r);
    push(rt);
}
ll query(int rt, int ql, int qr, int l , int r){
    if(ql <= l && r <= qr) return sum[rt];
    int mid = (l + r) >> 1;
    ll ans = 0;
    if(ql <= mid) ans += query(rt << 1, ql , qr, l, mid);
    if(qr > mid) ans += query(rt << 1|1, ql, qr, mid + 1, r);
    return ans;
}
int main(){
    int n, m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&val[i]);
    }
    init();
    build(1,n,1);
    while(m--){
        int type, l, r;
        scanf("%d%d%d",&type,&l,&r);
        if(type == 1)
            update(1,l,r,1,n);
        else
            printf("%lld\n",query(1,l,r,1,n));
    }
    return 0;
}
