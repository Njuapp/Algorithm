#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <queue>
#include <bitset>
using namespace std;
typedef long long int ll;
int n, x;
int main() {
    int pw = 1 << 17;
    cin >> n >> x;
    if(n == 2 && x == 0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    if(n == 2 ){
        cout<<0<<" "<<x<<endl;
        return 0;
    }
    else if(n == 1){
        cout<<x<<endl;
        return 0;
    }
    int y = 0;
    for(int i = 1; i <= n - 3; i ++){
        cout << i <<" ";
        y = y ^ i;
    }
    if(y == x){
        cout<<pw <<" "<<pw * 2<<" "<< (pw^(pw<<1)) <<endl;
    }
    else{
        cout<<0<<" "<<pw <<" "<< (pw ^ y ^ x) <<endl;
    }
    return 0;
}