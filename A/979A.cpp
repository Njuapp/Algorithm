#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <queue>
#include <cmath>
#include <bitset>
using namespace std;
const int maxn = 200010;
typedef long long int ll;
typedef pair<ll,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
int main(){
    ll n;
    cin >> n;
    if(n % 2){
        cout<<(n+1)/2<<endl;
    }
    else if(n)
        cout<<(n+1);
    else
        cout<<0;
    return 0;
}