#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pll;
#define rep(i,n) for(int i = 0; i < (n); i ++)
int n,k;
string s;
int cnt[26];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k >> s;
    for(int i = 0; i < s.length(); i ++){
        cnt[s[i]-'a']++;
    }
    int idx = 0;
    int ans = 0;
    int len = 0;
    while(idx < 26){
        if(cnt[idx] == 0){
            idx ++;
            continue;
        }
        ans += (idx + 1);
        len += 1;
        if(len == k){
            break;
        }
        idx += 2;
    }
    if(len < k){
        cout<<-1<<endl;
    }
    else{
        cout<<ans <<endl;
    }
    return 0;
}