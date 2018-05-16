#include <bits/stdc++.h>
#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
using namespace std;
typedef long long int ll;
const int maxn = 1005;
int n;
int arr[maxn];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >>arr[i];
    sort(arr, arr+n);
    cout<< arr[(n-1)/2];
    return 0;
}