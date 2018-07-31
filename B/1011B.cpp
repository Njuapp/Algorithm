#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pll;
#define rep(i,n) for(int i = 0; i < (n); i ++)
int n,m;
int a[105];
bool valid(int day){
    int people = 0;
    for(int i = 1; i <= 100; i ++){
        people += (a[i] / day);
    }
    return people >= n;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= m; i ++){
        int tmp;
        cin >> tmp;
        a[tmp]++;
    }
    int lo = 0, hi = 200;
    while(lo + 1< hi){
        int mid = (lo + hi )/ 2;
        if(valid(mid))
            lo = mid;
        else
            hi = mid;
    }
    cout<<lo<<endl;
    return 0;
}