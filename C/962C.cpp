/*
 * Author: Cheng Hang on 04/11/2018
 * All Copyrights Reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
using namespace std;
typedef long long int ll;
using namespace std;
int ans = 10;
void mindelete(string n,int cur, int del){
    if(n.empty()){
        if(cur != 0 && int(sqrt(cur))*int(sqrt(cur)) == cur){
            ans = min(del, ans);
        }
        return;
    }
    if(!(cur == 0&& n[0] == '0'))
        mindelete(n.substr(1), cur * 10 + n[0] - '0', del);
    mindelete(n.substr(1), cur  , del + 1);
}
int main(){
    string n;
    cin >> n;
    mindelete(n,0,0);
    if(ans == 10)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}