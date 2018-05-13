#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>

using namespace std;
const int maxn = 100000;
typedef long long int ll;
typedef pair<int,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
int n,m;
ll a[200010];
ll b[200010];
int main(){
    cin >> n >> m;
    forn(i,n)
        scanf("%lld", &a[i]);
    forn(i,m)
        scanf("%lld", &b[i]);
    int curid = 0;
    ll prev = 0;
    forn(i,m){
        while(b[i] > prev + a[curid]){
            prev += a[curid];
            curid++;
        }
        cout << curid + 1<<" "<<b[i]-prev<<endl;
    }
    return 0;
}