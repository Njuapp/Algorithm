#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
const int maxn= 1005;
string s,t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s >> t;
    int num = 0;
    vector<int> nums(26,0);
    vector<int> cnts(26,0);
    for(int i = 0; i < s.length(); i ++){
        if(s[i] == '?'){
            num ++;
        }
        else{
            cnts[s[i]-'a']++;
        }
    }
    vector<int> cntt(26,0);
    for(int i = 0; i < t.length(); i ++){
        cntt[t[i]-'a'] ++;
    }
    int res = 0;
    while(true){
        for(int i = 0; i < 26; i ++){
            if(cnts[i] >= cntt[i]){
                cnts[i] -= cntt[i];
            }
            else{
                num -= (cntt[i] - cnts[i]);
                nums[i] += (cntt[i] - cnts[i]);
                cnts[i] = 0;
            }
        }
        if(num < 0)
            break;
        res ++;
    }
    vector<int> cnt(26,0);
    for(char ch: s){
        if(ch != '?')
            cnt[ch-'a'] ++;
    }
    string fill;
    for(int i = 0; i < 26; i ++){
        if(res * cntt[i] - cnt[i] > 0)
        fill += string( res * cntt[i] - cnt[i], 'a' + i);
    }
    int idx = 0;
    for(int i = 0; i < s.length(); i ++){
        if(s[i] == '?'){
            if(idx < fill.length())
                s[i] = fill[idx++];
            else
                s[i] = 'a';
        }
    }
    cout<<s;
    return 0;
}