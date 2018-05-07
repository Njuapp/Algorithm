#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll n;
const int maxn = 100010;
ll arr[maxn];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> arr[i];
    sort(arr + 1, arr + 1 + n);
    arr[1] = 1;
    for(int i = 2; i <= n; i ++){
        if(arr[i] > arr[i-1])
            arr[i] = arr[i-1] + 1;
    }
    cout << arr[n] + 1;
    return 0;
}