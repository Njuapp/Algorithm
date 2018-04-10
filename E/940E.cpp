/*
 * Author: Cheng Hang on 04/10/2018
 * All Copyrights Reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <numeric>

typedef long long int lli;
using namespace std;
lli summary(vector<lli> a){
    lli res = 0;
    for(auto it = a.begin(); it != a.end(); it ++){
        res += *(it);
    }
    return res;
}
int main(){
    int n,c;
    cin >> n >> c;
    vector<lli> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(n < c){
        cout<<summary(a)<<endl;
        return 0;
    }
    vector<lli> maxc;
    multiset<lli> sum;
    for(int i = 0; i < c; i++)
        sum.insert(a[i]);
    maxc.push_back(*sum.begin());
    for(int i = c; i < n; i++){
        auto it = sum.find(a[i-c]);
        sum.erase(it);
        sum.insert(a[i]);
        maxc.push_back(*sum.begin());
    }
    vector<lli> res(n);
    res[c-1] = maxc[0];
    for(int i = c; i < n; i++){
        res[i] = max(res[i-1], res[i-c] + maxc[i-c + 1]);
    }
    cout<< summary(a) - res[n-1]<<endl;
    return 0;
}