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
int n,m;
LL row[105], col[105];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    LL x = 0;
    for(int i = 1; i <= n; i ++){
        cin >> row[i];
        x = x ^ row[i];
    }
    for(int i = 1; i <= m; i ++){
        cin >> col[i];
        x = x ^ col[i];
    }
    if(x != 0){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    LL first = col[1];
    for(int i = 2; i <= n; i ++)
        first ^= row[i];
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(i == 1 && j == 1)
                cout<<first<<" ";
            else if(i == 1)
                cout<<col[j]<<" ";
            else if(j == 1)
                cout<<row[i]<<" ";
            else
                cout <<0<<" ";
        }
        cout<<endl;
    }
    return 0;
}