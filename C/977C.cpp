#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long int ll;
int n,k;
ll arr[200010];
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    if( k == 0){
        if(arr[0] == 1)
            cout<<-1;
        else
            cout<<arr[0] - 1;
    }
    else{
        if(arr[k-1] == arr[k])
            cout << -1;
        else
            cout << arr[k-1];
    }
    return 0;
}