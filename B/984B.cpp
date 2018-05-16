#include <bits/stdc++.h>
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
using namespace std;
typedef long long int ll;
const int maxn = 100;
int n,m;
int arr[105][105];
int check[105][105];
void addbomb(int i, int j){
    forn(di,3){
        forn(dj,3){
            if(di == 1 && dj == 1)
                continue;
            int x = i + di - 1;
            int y = j + dj - 1;
            check[x][y] ++;
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char tmp;
            cin >> tmp;
            if(tmp == '.'){
                arr[i][j] = 0;
            }
            else if(tmp == '*'){
                addbomb(i,j);
                arr[i][j] = -1;
            }
            else{
                arr[i][j] = tmp - '0';
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j] != -1 && arr[i][j] != check[i][j]){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}