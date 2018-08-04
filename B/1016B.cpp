#include <iostream>
#include <utility>
#include <set>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
#define rep(i,n) for(int i = 0; i < (n); i ++)
int n,m,q,l,r;
string s,t;
int sum[1010];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> q ;
    cin >> s >> t;
    int cnt = 0;
    for(int i = 0; i <= n - m; i ++){
        if(s.substr(i,m) == t){
            cnt ++;
            
        }
        sum[i+1] = cnt;
    }
    while(q--){
        cin >> l >> r;
        if(r-m+1 > l - 1)
            cout << sum[r-m+1] - sum[l-1]<<endl;
        else
            cout << 0<<endl;
    }
    return 0;
}