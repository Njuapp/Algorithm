#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 200005;
typedef pair<int,int> pii;
int n, q, c;
int cnt[11][105][105];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q >> c;
    forn(i, n){
        int x,y,s;
        cin >> x >> y >> s;
        cnt[s][x][y] ++;
    }
    for(int i = 0; i <= c; i++){
        for(int j = 1; j <= 100; j ++){
            for(int k = 1; k <= 100; k ++){
                cnt[i][j][k] += ( cnt[i][j-1][k] + cnt[i][j][k-1] - cnt[i][j-1][k-1]);
            }
        }
    }
    for(int i = 0; i < q; i ++){
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for(int j = 0; j <= c ; j++){
            ans += ((j + t) %(c+1)) *(cnt[j][x2][y2] - cnt[j][x1-1][y2] - cnt[j][x2][y1-1] + cnt[j][x1-1][y1-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}