#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
const int maxn= 105;
int n;
ll d;
ll a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> d;
    forn(i,n)
        cin >> a[i];
    int res = 2;
    forn(i, n-1)
    {
        if(a[i+1] - a[i] > 2 * d){
            res+=2;
        }
        else if(a[i+1] - a[i] == 2 *d){
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}