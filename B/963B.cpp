#include <cstdio>
#include <vector>
#define pb push_back
typedef long long ll;
using namespace std;
const int maxn = 200005;
vector<int> graph[maxn];
int sz[maxn];
int n,root;
void getsize(int s){
    sz[s] = 1;
    for(int u: graph[s]){
        getsize(u);
        sz[s] += sz[u];
    }
}
void dfs(int s){
    for(int u: graph[s] ){
        if(sz[u] % 2 == 0)
            dfs(u);
    }
    printf("%d\n",s);
    for(int u: graph[s] ){
        if(sz[u] % 2)
            dfs(u);
    }
}
int main()
{
    scanf("%d", &n);
    for(int k = 1; k <= n; k++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp){
            graph[tmp].push_back(k);
        }
        else{
            root = k;
        }
    }
    if(n % 2 == 0){
        printf("NO");
        return 0;
    }
    else{
        printf("YES\n");
        getsize(root);
        dfs(root);
    }
    return 0;
}
