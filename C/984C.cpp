#include <bits/stdc++.h>
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
using namespace std;
typedef long long int ll;
const int maxn = 100;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while(n--){
        ll p,q,b;
        cin >> p >> q >> b;
        ll cd = gcd(p,q);
        q = q / cd;
        b = gcd(q,b);
        while(b!=1){
            while(q % b == 0) q = q/b;
            b = gcd(q,b);
        }
        if(q == 1)
            cout<<"Finite"<<endl;
        else
            cout<<"Infinite"<<endl;
    }
    return 0;
}