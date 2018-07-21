#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
const int maxn= 1005;
int n,k;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    forn(i,n)
        cin >> a[i];
    sort(a, a + n );
    int res = 0;
    forn(i,n){
        if(2 * k >= a[i])
            k = max(k, a[i]);
        else{
            while(2 * k < a[i]){
                k *= 2;
                res++;
            }
            k = max(k, a[i]);
        }
    }
    cout<<res;
    return 0;
}