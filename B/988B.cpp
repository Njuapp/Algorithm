#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 50;
typedef pair<int,int> pii;
int sub(string a, string b){
    if(a.length() > b.length()){
        string tmp = b;
        b = a;
        a = tmp;
    }
    for(int  i = 0; i  + a.length() - 1< b.length(); i ++){
        string sub = b.substr(i,a.length());
        if(a == sub) {
            return 1;
        }
    }
    return 0;
}
bool cmp(string a, string b){
    return a.length() < b.length();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string strs[100];
    forn(i,n)
        cin >> strs[i];
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < i; j ++){
            if(!sub(strs[i], strs[j]))
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    sort(strs, strs+n, cmp);
    forn(i,n)
        cout<<strs[i]<<endl;
    return 0;
}