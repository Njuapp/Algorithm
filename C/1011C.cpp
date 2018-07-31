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
int a[1005], b[1005];
int coeff[2005];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        cin >> coeff[2 * i - 1];
    cin >> coeff[2 * n];
    for(int i = 1; i < n; i ++)
        cin >> coeff[2 * i];
    double weight = m;
    for(int k = 2 * n; k >= 1; k --){
        if(coeff[k] == 1){
            cout<<-1<<endl;
            return 0;
        }
        double burnt = weight / (coeff[k] - 1);
        weight += burnt;
    }
    printf("%.10lf\n",weight - m);
    return 0;
}