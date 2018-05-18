#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 100010;
typedef pair<int,int> pii;
int n;
int a[maxn];
pii k[maxn];
int p[maxn];
int sz[maxn];
int ans;
int maxsz;
set<pii> root;
int find(int node){
    while(node != p[node]) 
    {
    	p[node] = p[p[node]];
    	node = p[node];
    }
    return node;
}
void unions(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(sz[pa] > sz[pb]){
        p[pb] = pa;
        root.erase(pii(sz[pb],pb));
        root.erase(pii(sz[pa],pa));
        sz[pa] += sz[pb];
        root.insert(pii(sz[pa],pa));
    }
    else{
        p[pa] = pb;
        root.erase(pii(sz[pb],pb));
        root.erase(pii(sz[pa],pa));
        sz[pb] += sz[pa];
        root.insert(pii(sz[pb],pb));
    }
    //cout<<root.size()<<endl;
}
void check(int k){
    auto s = root.begin();
    auto e = root.end();
    e --;
    if(s->first != e->first) return;
    int nowsz = root.size();
    if(nowsz > maxsz){
        maxsz = nowsz;
        ans = k;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i= 1; i <= n ; i++) {
        cin >> a[i];
        k[i].first = a[i];
        k[i].second = i;
        sz[i] = 1;
    }
    sort(k+1, k+n+1);
    for(int i = 1; i <= n ; i++){
        int nowk = k[i].first + 1;
        int idx = k[i].second;
        p[idx] = idx;
        root.insert(pii(1, idx));
        if(idx-1 >=1 && p[idx-1] != 0)
            unions(idx, idx - 1);
        if(idx+1 <=n && p[idx+1] != 0)
            unions(idx, idx + 1);
        //check valid or not
        //and the set size , if bigger than before, update ans
        check(nowk);
    }
    cout<<ans;
    return 0;
}