#include <iostream>
#include <utility>
#include <set>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
#define rep(i,n) for(int i = 0; i < (n); i ++)
int n, a, b;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> a >> b;
    if(a > 1 && b > 1){
        cout<<"NO";
        return 0;
    }
    if(a == 1 && b == 1 && n <= 3 && n > 1){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    if(a > 1){
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                if(i == j)
                    cout<<'0';
                else if(i < n - a + 1 && j < n - a + 1)
                    cout<<'1';
                else
                    cout<<'0';
            }
            cout<<endl;
        }
    }
    if(b > 1){
        rep(i,n){
            rep(j,n){
                if(i == j)
                    cout<<'0';
                else if(i < n - b + 1 && j < n - b + 1)
                    cout<<'0';
                else
                    cout<<'1';
            }
            cout<<endl;
        }
    }
    if(a == 1 && b == 1){
        rep(i,n){
            rep(j,n){
                if(abs(i-j) == 1)
                    cout<<'1';
                else
                    cout<<'0';
            }
            cout<<endl;
        }
    }
    return 0;
}
