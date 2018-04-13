//
// Created by 杭诚 on 2018/4/7.
//
#include <iostream>
#include <vector>
#include <set>
typedef long long int ll;
using namespace std;
int main(){
    ll n;
    cin >> n;
    ll sum = 0;
    int left = 0;
    while(n!= 1){
        sum += ((n >>1)<< left);
        left++;
        n = (n + 1)>> 1;
    }
    cout<<sum<<endl;
    return 0;
}
