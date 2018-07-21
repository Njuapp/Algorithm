#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
const int maxn= 100005;
int n;
int a[maxn];
unordered_map<int,int> leftcnt;
unordered_map<int,int> rightcnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n ;
    forn(i,n){
        cin >> a[i+1];
    }
    for(int i = 1; i <= n; i++){
        rightcnt[a[i]]++;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        leftcnt[a[i]] ++;
        rightcnt[a[i]] --;
        if(rightcnt[a[i]] == 0)
            rightcnt.erase(a[i]);
        if(leftcnt[a[i]] == 1) {
            ans += rightcnt.size();
        }
    }
    cout<<ans<<endl;
    return 0;
}