#include "bits/stdc++.h"
using namespace std;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
const int maxn= 100;
int n;
string a[maxn];
string b[maxn];
int cnt[4][3];
int char2idx(char ch){
    switch (ch){
        case 'S':
            return 0;
        case 'M':
            return 1;
        case 'L':
            return 2;
        default:
            return -1;
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    forn(i,n) {
        cin >> a[i];
        int idx = a[i].length() - 1;
        int row = char2idx(a[i][idx]);
        cnt[idx][row]++;
    }
    forn(i,n) {
        cin >> b[i];
        int idx = b[i].length() - 1;
        int row = char2idx(b[i][idx]);
        cnt[idx][row]--;
    }
    int res = 0;
    forn(i,4){
        int sum = 0;
        forn(j,3){
            sum += abs(cnt[i][j]);
        }
        res += (sum / 2);
    }
    cout<<res<<endl;
    return 0;
}