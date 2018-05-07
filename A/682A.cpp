#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll n,m;
ll shit[5];
ll shit2[5];
int main() {
    cin >> n >> m;
    ll sum = 0;
    for(int i = 0; i < 5; i ++){
        shit[i] = n / 5 + ( i >= 1 && n % 5 >= i);
        shit2[i] = m / 5 + (i >= 1 && m % 5 >= i);
    }
    for(int i = 0; i < 5; i ++){
        sum += shit[i] * shit2[(5 -i) % 5];
    }
    cout << sum <<endl;
    return 0;
}