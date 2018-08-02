#include <iostream>
#include <utility>
#include <set>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
#define rep(i,n) for(int i = 0; i < (n); i ++)
int n;
set<int> st;
size_t brute(int n){
    st.clear();
    for(int i = 0; i <= n; i ++){
        for(int j = 0; j + i <= n; j ++){
            for(int k = 0; k + j + i <= n; k ++){
                    st.insert(i + 5 * j + 10 * k + 50 *(n - i - j - k));
            }
        }
    }
    return st.size();
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    if(n <= 12)
        cout<<brute(n)<<endl;
    else
        cout<<brute(12) + 49 * (LL)(n-12)<<endl;
    return 0;
}
