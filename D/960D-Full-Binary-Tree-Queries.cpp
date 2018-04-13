#include <iostream>
using namespace std;
typedef long long int ll;
ll a[128];
int level(ll  n){
    int l = 0;
    while(n){
        n = n >> 1;
        l ++;
    }
    return l;
}
ll idx2num(ll idx){
    int l = level(idx);
    ll nums = 1;
    nums = nums << (l-1);
    ll val = (idx - nums - a[l]) % nums;
    if(val < 0)
        val += nums;
    val += nums;
    return val;
}
int main(){
    int Q;
    cin >> Q;
    while(Q--){
        int t;
        cin >> t;
        if(t == 1){
            ll X, K;
            cin >> X >> K;
            int l = level(X);
            a[l] += K;
        }
        else if(t == 2){
            ll X, K;
            cin >> X >> K;
            int l = level(X);
            ll nums = 1;
            nums = nums << (l-1);
            ll shift = K % nums;
            if(shift < 0)
                shift += nums;
            for(int i = l; i < 128; i++){
                a[i] += shift;
                shift <<= 1;
            }
        }
        else{
            ll X;
            cin >> X;
            int l = level(X);
            ll nums = 1;
            nums = nums << (l-1);
            ll idx = (X - nums + a[l]) % nums;
            if(idx < 0)
                idx += nums;
            idx += nums;
            while(idx){
                cout<<idx2num(idx)<<" ";
                idx /= 2;
            }
            cout << endl;
        }


    }
    return 0;
}
