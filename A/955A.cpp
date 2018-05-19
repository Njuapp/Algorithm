#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 100010;
typedef pair<int,int> pii;
int hh,mm;
int H, D, C, N;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> hh >> mm;
    cin >> H >> D >> C >> N;

    if(hh >= 20){
        double cost = (H / N + (H % N != 0)) * (double)C * 0.8;
        printf("%.4lf", cost);
        return 0;
    }
    double cost1 = (H / N + (H % N != 0)) * C;
    double cost2;
    double mini = 20 * 60 - hh * 60 - mm;
    H += mini * D;
    cost2 = (H / N + (H % N != 0)) * C * 0.8;
    printf("%.4lf", min(cost1, cost2));
    return 0;
}