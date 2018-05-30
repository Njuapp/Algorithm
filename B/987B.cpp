#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const ll maxn = 1e5;
typedef pair<int,int> pii;
double x,y;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> x >> y;
    double z = log(x)*y - log(y)*x;
    if(z < 0)
        cout<<"<";
    else if(z > 0)
        cout<<">";
    else
        cout<<"=";


    return 0;
}