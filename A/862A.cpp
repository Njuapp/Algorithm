#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long int ll;
int n, x;
int arr[110];
int main() {
    cin >> n >> x;
    for(int i = 0; i < n; i ++)
        cin >> arr[i];
    sort(arr, arr + n);
    int sum = 0;
    int rm = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > x)
            break;
        if(arr[i] == x){
            rm = 1;
            break;
        }
        sum ++;
    }

    cout << x - sum + rm<<endl;
    return 0;
}