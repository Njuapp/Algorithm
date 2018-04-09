#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int lli;
using namespace std;
struct Tap{
    lli a;
    lli temp;
};
int main(){
    int n;
    lli T;
    cin >> n >> T;
    vector<Tap> taps(n);
    for(int i = 0; i < n; i++)
        cin >> taps[i].a;
    for(int i = 0; i < n; i++)
        cin >> taps[i].temp;
    sort(taps.begin(), taps.end(), [](Tap a,Tap b)->bool{return a.temp < b.temp;});
    if(taps[0].temp > T || taps[n-1].temp < T){
        cout<<'0'<<endl;
        return 0;
    }
    lli sum_nom = 0;
    lli denom = 0;
    vector<double > bin(n);
    for(int i = 0; i < n ;i++){
        sum_nom += taps[i].temp * taps[i].a;
        denom += taps[i].a;
        bin[i] = sum_nom / (double)denom;
    }
    if(bin[n-1] == T){
        cout<<denom<<endl;
        return 0;
    }
    if(bin[n-1] > T) {
        auto idx = upper_bound(bin.begin(), bin.end(), T) - bin.begin();
        double res = 0;
        sum_nom = 0;
        denom = 0;
        for (int i = 0; i < idx; i++) {
            res += taps[i].a;
            sum_nom += taps[i].temp * taps[i].a;
            denom += taps[i].a;
        }
        res += (T * denom - sum_nom) / (double) (taps[idx].temp - T);
        printf("%.15f", res);
    }
    else {
        sum_nom = 0;
        denom = 0;
        for(int i = n-1; i>= 0 ;i--){
            sum_nom += taps[i].temp * taps[i].a;
            denom += taps[i].a;
            bin[i] = sum_nom / (double)denom;
        }
        auto idx = lower_bound(bin.begin(), bin.end(), T) - bin.begin() - 1;
        double res = 0.0;
        sum_nom = 0;
        denom = 0;
        for(int i = n - 1; i > idx; i --){
            res += taps[i].a;
            sum_nom += taps[i].temp * taps[i].a;
            denom += taps[i].a;
        }
        res += (T * denom - sum_nom) / (double) (taps[idx].temp - T);
        printf("%.15f", res);
    }
    return 0;
}