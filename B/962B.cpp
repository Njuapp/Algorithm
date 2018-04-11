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
int main(){
    int n, a, b;
    scanf("%d%d%d",&n,&a,&b);
    string s;
    cin >> s;
    vector<int> len;
    int res = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '.')
            res++;
        else{
            if(res != 0)
                len.push_back(res);
            res = 0;
        }
    }
    if(res != 0)
        len.push_back(res);
    int ans = 0;
    for(auto l: len){
        if(l%2==0){
            int dec_a = min(a, l/2);
            int dec_b = min(b, l/2);
            ans += dec_a + dec_b;
            a -= dec_a;
            b -= dec_b;
        }
        else{
            if(a > b){
                int dec_a = min(a, l / 2 + 1);
                int dec_b = min(b, l / 2);
                ans += dec_a + dec_b;
                a -= dec_a;
                b -= dec_b;
            }
            else{
                int dec_a = min(a, l / 2);
                int dec_b = min(b, l / 2 + 1);
                ans += dec_a + dec_b;
                a -= dec_a;
                b -= dec_b;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}