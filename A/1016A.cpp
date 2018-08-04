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
LL n,m;
LL a[200001];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    rep(i,n){
        cin >> a[i];
    }
    LL sum = 0;
    rep(i,n){
        cout << (sum + a[i]) / m - sum / m <<" ";
        sum += a[i];
    }
    return 0;
}