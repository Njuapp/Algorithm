#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
const int maxn = 200010;
typedef pair<int,int> pii;
int n ;
int w[maxn];
priority_queue<pii,vector<pii>,  greater<> > inq;
priority_queue<pii,vector<pii>, less<> > exq;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        inq.push(make_pair( tmp, i+1));
    }
    for(int i = 0; i < 2 * n ; i++){
        char ch;
        cin >> ch;
        if(ch == '0'){
            auto ele = inq.top();
            inq.pop();
            cout<<ele.second<<" ";
            exq.push(ele);
        }
        else{
            auto ele = exq.top();
            exq.pop();
            cout<<ele.second<<" ";
        }
    }
    return 0;
}