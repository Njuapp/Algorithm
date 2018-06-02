#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 200005;
typedef pair<int,int> pii;
unordered_map<int, pii> mp;
int k;
vector<int> veci[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> k;
    int ans[4];
    bool flag = false;
    forn(i,k){
        int n;
        cin >> n;
        int sum = 0;
        forn(j,n){
            int val;
            cin >> val;
            sum += val;
            veci[i].push_back(val);
        }
        forn(j, n){
            if(mp.find(sum-veci[i][j]) != mp.end() && mp[sum-veci[i][j]].first != i + 1)
            {
                flag = true;
                ans[0] = mp[sum-veci[i][j]].first;
                ans[1] = mp[sum-veci[i][j]].second;
                ans[2] = i+1;
                ans[3] = j+1;
            }
            mp[sum-veci[i][j]] = make_pair(i+1,j+1);
        }
    }
    if(flag){
        cout<<"YES"<<endl;
        cout<<ans[0]<<" "<<ans[1]<<endl;
        cout<<ans[2]<<" "<<ans[3]<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}