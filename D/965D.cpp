#include <iostream>
#include <climits>
using namespace std;
typedef long long int ll;
const int maxn = 100010;
ll l, w;
ll arr[maxn];
int main(){
    cin >> w >> l;
    for(int i = 1; i < w; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    ll mi = INT_MAX;
    for(int i = l; i < w; i ++){
        mi = min(mi, arr[i] - arr[i-l]);
    }
    cout<<mi<<endl;
    return 0;
}