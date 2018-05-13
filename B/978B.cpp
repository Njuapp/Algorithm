#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>

using namespace std;
const int maxn = 100000;
typedef long long int ll;
typedef pair<int,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
int main(){
    int n;
    cin >> n;
    char str[105];
    cin >> str;
    int i = 0;
    int ans = 0;
    while(i < n){
        if(str[i] != 'x')
        {
            i++;
            continue;
        }
        int sum = 0;
        int k = i;
        for(; k < n; k++){
            if(str[k] == 'x')
                sum++;
            else{
                break;
            }
        }
        i = k;
        ans += (sum >= 3 ? sum - 2: 0);
    }
    cout<< ans<<endl;
    return 0;
}