#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
const int N= 200005;
int n;
vector<pii> vsi;
vector<string> vstr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i ++){
        string t;
        cin >> t;
        vstr.push_back(t);
        int temp;
        cin >> temp;
        while(temp--){
            int occ;
            cin >> occ;
            vsi.push_back(make_pair(i, occ));
        }
    }
    sort(vsi.begin(), vsi.end(), [](pii a, pii b)->bool{
        if(a.second < b.second)
            return true;
        else if(a.second > b.second)
            return false;
        return vstr[a.first].length() < vstr[b.first].length();
    });
    int prev = 1;
    for(auto item: vsi){
        while(prev < item.second){
            prev ++;
            cout<<'a';
        }
        if(prev != item.second){
            if(prev >= vstr[item.first].length() + item.second)
                continue;
            else{
                for(int s = prev - item.second; s < vstr[item.first].length(); s ++){
                    cout<<vstr[item.first][s];
                    prev++;
                }
            }
        }
        else{
            cout<<vstr[item.first];
            prev += vstr[item.first].length();
        }
    }
    return 0;
}