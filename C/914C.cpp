#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pll;
#define rep(i,n) for(int i = 0; i < (n); i ++)
int n, type, l, r, i, x, y;
int a[2000005];
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

void buildtree(int start, int end, int curr){
    if(start == end){
        cin >> a[curr];
        return;
    }
    int mid = (start + end) / 2;
    buildtree(start, mid, curr * 2);
    buildtree(mid + 1, end, curr * 2 + 1);
    a[curr] = gcd(a[curr * 2], a[curr * 2 + 1]);
}

void update(int start, int end, int curr, int idx, int val){
    if(start == end){
        a[curr] = val;
        return;
    }
    int mid = (start + end) / 2;
    if(idx <= mid)
        update(start, mid, curr * 2, idx, val);
    else
        update(mid + 1, end, curr * 2 + 1, idx, val);
    a[curr] = gcd(a[curr*2], a[curr*2+1]);
}

int query(int start, int end, int curr, int l, int r, int x){
    if(start == end){
            return 1;
    }
    int mid = (start + end) / 2;
    int ans = 0;
    if(l <= mid && a[curr * 2] % x != 0)
        ans += query(start, mid, curr * 2, l, r, x);
    if(r >= mid + 1 && a[curr * 2 + 1] % x != 0 && ans <= 1)
        ans += query(mid + 1, end, curr * 2 + 1, l, r, x);
    return ans;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    buildtree(1, n, 1);
    int q;
    cin >> q;
    while(q--){
        cin >> type;
        if(type == 1){
            cin >> l >> r >> x;
            if(query(1, n, 1, l, r, x) > 1)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
        else{
            cin >> i >> y;
            update(1, n, 1, i, y);
        }
    }
    return 0;
}
