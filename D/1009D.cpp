#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
const int maxm= 100005;
int n,m;
int gcd(int a,int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    if(m < n - 1)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    vector<vector<int>> res;
    for(int i = 1; i <= n; i ++){
        for(int j = i + 1; j <= n; j ++){
            if(gcd(i,j) == 1){
                res.push_back(vector<int>{i,j});
            }
            if(res.size() == m){
                cout<<"Possible"<<endl;
                for(auto item: res)
                    cout<<item[0]<<" "<<item[1]<<endl;
                return 0;
            }
        }
    }
    cout<<"Impossible"<<endl;
    return 0;
}