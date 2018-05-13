#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <queue>
#include <cmath>
#include <bitset>
using namespace std;
const int maxn = 105;
typedef long long int ll;
typedef pair<ll,int> pii;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
struct exam{
    int s;
    int d;
    int c;
    int idx;
};
bool cmp(exam a, exam b){
    return a.d < b.d;
}
int n,m;
exam exs[maxn];
int ans[maxn];
int main(){
    cin >> n >> m;
    forn(i,m){
        scanf("%d %d %d", &exs[i].s, &exs[i].d, &exs[i].c);
        exs[i].idx = i + 1;
        ans[exs[i].d] = m+1;
    }
    sort(exs, exs+m, cmp);
    bool flag = true;
    for(int i = 0; i < m; i++){
        int days= 0;
        for(int j = exs[i].s; j < exs[i].d; j++){
            if(ans[j] == 0)
                days++;
        }
        if(days < exs[i].c){
            flag = false;
            break;
        }
        days = exs[i].c;
        for(int j = exs[i].s; days !=0&&j < exs[i].d; j++){
            if(ans[j] ==0){
                days--;
                ans[j] = exs[i].idx;
            }
        }
    }
    if(!flag){
        cout<<-1<<endl;
        return 0;
    }
    forn(i, n){
        cout<<ans[i+1]<<" ";
    }
    return 0;
}