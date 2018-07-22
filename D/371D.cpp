#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
const int N= 200005;
int a[N];
int cap[N];
int n;
int fa[N];
int find(int x){
    return (fa[x] == 0 || fa[x] == x) ? x : fa[x] = find(fa[x]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        cap[i] = a[i];
    }
    int m;
    cin >> m;
    while(m--){
        int type;
        cin >> type;
        if(type == 1){
            int p,x;
            cin >> p >> x;
            p = find(p);
            while(x > 0 && p <= n){
                int contain = min(a[p], x);
                a[p] -= contain;
                x -= contain;
                if(a[p] == 0)
                    fa[p] = find(p + 1);
                p = fa[p];
            }
        }
        else{
            int k;
            cin >> k;
            cout << cap[k] - a[k]<<endl;
        }
    }
    return 0;
}