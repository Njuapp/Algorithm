#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
#define rep(i,n) for(int i = 0; i < (n); i ++)
LL n, x, y;
string a;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> x >> y >> a;
    LL cnt = 0;
    for(int i = 0; i < a.length(); i ++){
        if((i == 0 ||a[i-1] == '1') && a[i] == '0')
            cnt++;
    }
    if(cnt == 0)
        cout<<0;
    else if(x > y)
        cout << cnt * y;
    else
        cout << (cnt - 1) * x + y;
    return 0;
}
