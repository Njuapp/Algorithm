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
const int maxn = 200010;
typedef long long int ll;
typedef pair<ll,int> pii;
typedef pair<int,int> edge;
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
int n,k;
pii r[maxn];
vector<int> graph[maxn];
bool cmp(pii a, pii b){
    return a.first < b.first;
}
int ans[maxn];
int main(){
    cin >> n >> k;
    forn(i,n) {
        ll tmp;
        scanf("%lld", &tmp);
        r[i+1] = make_pair(tmp, i+1);
    }
    forn(i,k){
        int x,y;
        scanf("%d%d",&x, &y);
        if(r[x].first > r[y].first)
            graph[x].push_back(y);
        else if(r[x].first < r[y].first)
            graph[y].push_back(x);
    }
    sort(r+1, r+n+1, cmp);
    int s = 1;
    int now[maxn];
    while(s<= n){
        int e = s;
        for(; e <= n; e++){
            if(r[e].first != r[s].first)
                break;
            int j = r[e].second;//j代表了原来的下标
            int tmpsum = s - 1;//小数字
            for(auto enemy: graph[j]){
                if(now[enemy]){//不能相连的小数字
                    tmpsum--;
                }
            }
            ans[j] = tmpsum;
        }
        for(int p= s; p < e; p++){
            now[r[p].second] = 1;
        }
        s = e;
    }
    forn(i,n)
        printf("%d ", ans[i+1]);
    return 0;
}