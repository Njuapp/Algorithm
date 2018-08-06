#include <iostream>
#include <utility>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
#define rep(i,n) for(int i = 0; i < (n); i ++)
string s;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.length(); i ++){
        int low = 0, high = 0;
        for(int j = i; j < s.length(); j ++){
            if(s[j] == '(') {
                low ++;
                high ++;
            }
            else if(s[j] == ')'){
                low --;
                high --;
            }
            else{
                low --;
                high ++;
            }
            if(high < 0) break;
            if(low < 0) low = 0;
            if(((j-i) & 1)&&low == 0)
                ans ++;
        }
    }
    cout<<ans<<endl;
    return 0;
}