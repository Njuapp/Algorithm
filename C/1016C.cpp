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
int n;
LL a[300005], b[300005];
LL sum[300005];
LL zig[300005];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i ++)
        cin >> b[i];
    for(int i = n; i >= 1; i --){
        sum[i] = sum[i+1] + a[i] + b[i];
    }
    for(int i = 1; i <= n; i ++){
        zig[1] += (i-1) * a[i] + (2 * n - i) * b[i];
    }
    for(int i = 2; i <= n; i ++){
        zig[2] += i * b[i] + (2 * n + 1 - i) * a[i];
    }
    for(int i = 3; i <= n; i += 2){
        zig[i] = zig[i-2];
        zig[i] -= ((2 * i - 6) * a[i-2] + (2 * i - 5) * a[i-1] + (2 *n - 1) * b[i-2] + (2 * n - 2) * b[i-1]);
        zig[i] += 2 * sum[i];
    }
    for(int i = 4; i <= n; i += 2){
        zig[i] = zig[i-2];
        zig[i] -= ((2 * i - 6) * b[i-2] + (2 * i - 5) * b[i-1] + (2 * n - 1) * a[i-2] + (2 * n - 2) * a[i-1]);
        zig[i] += 2 * sum[i];
    }
    LL maxi = zig[1];
    LL prev = 0;
    for(int i = 1; i <= n; i ++){
        if(i % 2)
            prev += ((2 * i - 2) * a[i] + (2 * i - 1) * b[i]);
        else
            prev += ((2 * i - 2) * b[i] + (2 * i - 1) * a[i]);
        maxi = max(maxi, prev + zig[i+1]);
    }
    cout << maxi<<endl;
    return 0;
}