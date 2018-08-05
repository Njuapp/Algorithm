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
LL p;
int k;
int base[200];
int cnt;
int getbase(){
    int remainder = p % (-k);
    if(remainder < 0) remainder += k;
    return remainder % (-k);
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> p >> k;
    while(p){
        ++cnt;
        base[cnt] = getbase();
        p -= base[cnt];
        p /= (-k);
    }
    cout << cnt << endl;
    for(int i = 1; i <= cnt; i ++){
        cout<< base[i] << " ";
    }
    cout<<endl;
    return 0;
}
