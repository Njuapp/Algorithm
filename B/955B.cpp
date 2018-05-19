#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 100010;
typedef pair<int,int> pii;
int cnt[26];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        cnt[str[i]-'a'] ++;
    }
    int sz = 0;
    int single = 0;
    for(int i = 0; i < 26; i ++){
        if(cnt[i] != 0)
            sz++;
        if(cnt[i] == 1)
            single++;
    }
    if(sz > 4)
        cout<<"No";
    else if(sz == 1)
        cout<<"No";
    else if(sz == 2 && single != 0)
        cout<<"No";
    else if(sz == 3 && single == 3)
        cout<<"No";
    else
        cout<<"Yes";
    return 0;
}