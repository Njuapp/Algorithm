#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <queue>
#include <bitset>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
#define forn(i,n) for(int (i)=0; (i) < (n); (i)++)
int arr[100000];
int n,k;
int key[256];
int len[256]={0};
int main() {
    cin >> n >>k;
    for(int i = 0; i < n; i ++)
        cin >> arr[i];
    forn(i,256)
        key[i]=-1;
    for(int i = 0; i < n; i++){
        if(key[arr[i]]==-1){
            int s = max(0, arr[i] - k + 1);
            while(key[s]!=-1)
                s++;
            int kk = s;
            int l = arr[i] - s + 1;
            if(s-1>=0 && key[s-1]!=-1&&len[s-1] + l <= k){
                kk = key[s-1];
                l = len[s-1]+l;
            }
            for(int m = s; m <= arr[i]; m++)
            {
                key[m] = kk;
            }
            len[arr[i]] = l;
        }
    }
    forn(i,n){
        cout<<key[arr[i]]<<" ";
    }
    return 0;
}