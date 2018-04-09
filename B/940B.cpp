/*
 * Author: Cheng Hang on 04/10/2018
 * All Copyrights Reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int lli;
using namespace std;
lli n, k, A, B;
int main(){

    cin >> n >> k >> A >> B;
    if(k == 1){
        cout<< A *(n-1)<<endl;
        return 0;
    }
    lli res = 0;
    while(n != 1){
        if(n < k){
            res += (n-1) * A;
            n = 1;
        }
        else if(n % k == 0){
            res += min(B, (n-n/k) *A);
            n = n/k;
        }
        else {
            res += (n%k)*A;
            n -= n%k;
        }
    }
    cout<<res<<endl;
    return 0;
}