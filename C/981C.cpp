#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 100005;
typedef pair<int,int> pii;
int n;
vector<int> g[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    forn(i, n-1){
        int s,t;
        cin >> s >> t;
        g[s].push_back(t);
        g[t].push_back(s);
    }
    vector<int> ones;
    vector<int> twos;
    vector<int> other;
    for(int i = 1; i <= n; i++){
        if(g[i].size() == 1)
            ones.push_back(i);
        else if(g[i].size() == 2)
            twos.push_back(i);
        else
            other.push_back(i);
    }
    if(other.size() > 1){
        cout<<"No";
        return 0;
    }
    cout<<"Yes"<<endl;
    if(other.size() == 0){
        cout<<1<<endl;
        cout<<ones[0] <<" "<<ones[1]<<endl;
        return 0;
    }
    cout<<ones.size()<<endl;
    for(auto k: ones)
        cout<<other[0]<<" "<<k<<endl;
    return 0;
}