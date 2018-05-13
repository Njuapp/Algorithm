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
#define in(k) scanf("%d",&(k));
#define out
int n;
int a[1005];
int occ[1005];
int main(){
    cin >> n;
    int sum = 0;
    forn(i,n) {
        cin >> a[i+1];
        if(occ[a[i+1]]==0)
            sum++;
        occ[a[i+1]] = i+1;
    }
    cout<<sum<<endl;
    forn(i,n){
        if(occ[a[i+1]] == i+1)
            cout<<a[i+1]<<" ";
    }
    return 0;
}