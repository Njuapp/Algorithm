/*
 * Author: Cheng Hang on 04/10/2018
 * All Copyrights Reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

typedef long long int lli;
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ch[26] = {0};
    for(int i = 0; i < n; i++)
        ch[s[i]-'a'] = 1;
    map<char,char> next;
    char last = '\0';
    for(int i = 25; i >= 0; i--){
        if(ch[i] == 1){
            next['a'+i] = last;
            last = ('a' + i);
        }
    }
    if( k > n){
        cout<<s;
        for(int i = 0; i < k - n; i++)
            cout<<last;
    }
    else{
        int tmp = k;
        k--;
        while(true){
            if(next[s[k]] == '\0'){
                s[k] = last;
                k--;
            }
            else{
                s[k] = next[s[k]];
                break;
            }

        }
        cout<<s.substr(0, tmp);
    }
    return 0;
}