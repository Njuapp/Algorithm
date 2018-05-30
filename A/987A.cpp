#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const ll maxn = 1e5;
typedef pair<int,int> pii;
int n;
int v[6];
string gem[6] = {"Reality", "Power", "Time","Space", "Soul", "Mind"};
string str[6] = {"red","purple", "green", "blue", "orange", "yellow"};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i ++){
        string s;
         cin >> s;
         for(int j = 0; j < 6; j ++){
             if(s == str[j]) {
                 v[j] = 1;
                 break;
             }
         }
    }
    cout<<6-n<<endl;
    for(int i = 0; i < 6; i ++){
        if(!v[i]){
            cout<<gem[i]<<endl;
        }
    }


    return 0;
}