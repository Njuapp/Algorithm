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
#define MAX 150000+10
ll a[MAX];
map<ll, int>mp;
int main(){
    int n;
    scanf("%d",&n);
    int cnt = n;
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        while(mp[a[i]]){
            a[mp[a[i]]-1] = 0;
            mp[a[i]] = 0;
            a[i] *= 2;
            cnt --;
        }
        mp[a[i]] = i+1;
    }
    cout<<cnt<<endl;
    for(int i = 0; i < n; i++){
        if(a[i])
            cout<<a[i]<<" ";
    }
    return 0;
}