#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const ll maxn = 1e18;
typedef pair<int,int> pii;
int p[50];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n/2; i ++){
        cin >> p[i];
    }
    sort(p, p+n/2);
    int ans = INT_MAX;
    int sum = 0;
    for(int  i = 0; i < n/2;i ++){
        sum+=abs (p[i]- (2*i+1));
    }
    ans = min(ans, sum);
    sum = 0;
    for(int  i = 0; i < n/2;i ++){
        sum+=abs (p[i]- (2*i+2));
    }
    ans = min(ans, sum);
    cout<<ans<<endl;
    return 0;
}