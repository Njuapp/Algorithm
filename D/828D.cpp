#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
const int N= 200005;
int n,k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    int dist = 2 * ((n-1) / k);
    if((n-1) % k >= 2)
        dist += 2;
    else if((n-1) % k == 1)
        dist += 1;
    cout<<dist<<endl;
    int start = 2;
    for(int i = 0; i < k; i ++){
        int len = (n-1)/k + (i < (n-1) % k);
        for(int j = 0; j < len; j ++){
            if(j == 0)
                cout<<1<<" ";
            else
                cout<<start - 1<<" ";
            cout<<start <<endl;
            start++;
        }
    }
    return 0;
}