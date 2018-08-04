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
int n;
bool valid(string s, int & cnt){
    int st = 0;
    bool lflag = true;
    for(int i = 0; i < s.length(); i ++){
        if(s[i] == '(')
            st ++;
        else
            st --;
        if(st < 0)
            lflag = false;
    }
    cnt = st;
    st = 0;
    bool rflag = true;
    for(int i = (int)s.length() - 1; i >= 0; i --){
        if(s[i] == ')')
            st ++;
        else
            st --;
        if(st < 0)
            rflag = false;
    }
    if(!lflag && !rflag)
        return false;
    return true;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    while(n--){
        string str;
        cin >> str;
        int key = 0;
        bool val = valid(str, key);
        if(!val)
            continue;
        mp[key] ++;
    }
    LL sum = 0;
    for(auto it = mp.begin(); it != mp.end(); it ++){
        if(it->first == 0)
            sum += (LL)it->second * it->second;
        else if(it->first > 0)
            sum += (LL)it->second * mp[-it->first];
    }
    cout<< sum <<endl;
    return 0;
}
