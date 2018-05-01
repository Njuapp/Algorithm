#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long int ll;
int n, k;
const int maxn = 100;
int field[maxn][maxn];
int ans[maxn][maxn];
void addrow(int row, int s, int e){
    for(int j = s; j < e; j++){
        int mini = max(s, j - k + 1 );
        int maxi = min(e - k, j );
        ans[row][j] += (maxi - mini + 1);
    }
}
void addcol(int col, int s, int e){
    for(int j = s; j < e; j++){
        int mini = max(s, j - k + 1 );
        int maxi = min(e - k, j );
        ans[j][col] += (maxi - mini + 1);
    }
}
void findmax(int& i, int& j){
    int maxi = 0;
    for(int r = 0; r < n; r ++){
        for(int c = 0; c < n; c ++){
            if(ans[r][c] > maxi){
                i = r;
                j = c;
                maxi = ans[r][c];
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < n; j++){
            if(str[j] == '.')
                field[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        int lastzero = -1;
        for(int j = 0; j <= n; j++){
            if(j == n|| field[i][j] == 0){
                int len = j - 1 - lastzero;
                if(len >= k){
                    addrow(i, lastzero+1, j);
                }
                lastzero = j;
            }
        }
    }
    for(int i = 0; i < n; i ++){
        int lastzero = -1;
        for(int j = 0; j <= n; j++){
            if(j == n|| field[j][i] == 0){
                int len = j - 1 - lastzero;
                if(len >= k){
                    addcol(i, lastzero+1, j);
                }
                lastzero = j;
            }
        }
    }
    int r = 0, c = 0;
    findmax(r, c);
    cout<<r + 1<<" "<<c + 1<<endl;
    return 0;
}