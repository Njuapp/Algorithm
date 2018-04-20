#include <map>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;
typedef long long ll;
ll n;
int q;
ll find(ll ind){
    while(ind%2 == 0){
        ind = ind / 2 + n;
    }
    return (ind + 1)/2;
}
int main(){
    scanf("%lld%d",&n,&q);
    while(q--){
        ll ind;
        scanf("%lld",&ind);
        printf("%lld\n", find(ind));
    }
    return 0;
}