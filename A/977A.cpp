#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll n;
int k;
int main() {
    cin >> n >> k;
    while(n){
        ll d = n % 10;
        if(k <= d)
        {
            n -= k;
            break;
        }
        k -= (d + 1);
        n = n / 10;
    }
    cout<< n<<endl;
    return 0;
}