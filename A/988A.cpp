#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 50;
typedef pair<int,int> pii;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k;
    cin >> n >> k;
    unordered_map<int,int> mp;
    forn(i,n){
        int tmp;
        cin >> tmp;
        mp[tmp] = i+1;
    }
    if(mp.size() < k){
        cout<<"NO";
        return 0;
    }
    else{
        cout<<"YES"<<endl;
        auto s = mp.begin();
        for(int i = 0; i < k; i ++, s++){
            cout<<s->second<<" ";
        }
    }
    return 0;
}