#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 100000;
int n, A, B;
int s[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> A >> B;
    int f ;
    int sum = 0;
    cin >> f;
    sum += f;
    if(n == 1)
    {
        cout<<0;
        return 0;
    }
    for(int i = 0; i < n-1; i++){
        cin >> s[i];
    }
    sort(s, s + n -1);
    for(int k = 0; k < n - 1; k ++){
        sum += s[k];
        if(f / (double)sum * A < B){
            cout<< n - k - 1;
            return 0;
        }
    }
    cout<<0;
    return 0;
}