#include <iostream>
using namespace std;
typedef long long ll;
int n;
ll R,B,P;
ll maxR, maxB;
ll ans;
int main(){
    cin >> n;
    while(n--){
        ll pos;
        char ch;
        cin >> pos >> ch;
        pos += 1e9 + 7;
        if(ch == 'R'){
            if(R) ans += pos - R, maxR = max(maxR, pos - R);
            R = pos;
        }
        else if(ch == 'B'){
            if(B) ans += pos - B, maxB = max(maxB, pos - B);
            B = pos;
        }
        else{
            if(R) ans += pos - R, maxR = max(maxR, pos - R);
            if(B) ans += pos - B, maxB = max(maxB, pos - B);
            if(P){
                ans += min(0LL, pos - P - maxR - maxB);
            }
            R = B = P = pos;
            maxB = maxR = 0;
        }
    }
    cout << ans <<endl;
    return 0;
}