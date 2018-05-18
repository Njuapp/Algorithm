#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 100000;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string str;
    cin >> str;
    int last = -1;
    forn(i,n){
        if(str[i] == '1'){
            if(last != -1){
                if(i - last == 1){
                    cout<<"No";
                    return 0;
                }
                else if(i - last > 3){
                    cout<<"No";
                    return 0;
                }
            }
            else{
                if( i >= 2){
                    cout<<"No";
                    return 0;
                }
            }
            last = i;
        }
    }
    if(last == -1){
        cout<<"No";
        return 0;
    }
    if( n - last >= 3){
        cout<<"No";
        return 0;
    }
    cout<<"Yes";
    return 0;
}