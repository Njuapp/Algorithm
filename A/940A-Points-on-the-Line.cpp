/*
 * Author: Cheng Hang on 04/09/2018
 * All Copyrights Reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int lli;
using namespace std;
int main(){
    int n, d;
    cin >> n >> d;
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int maxremain = -1;
    for(int i = 0; i < n; i++){
        for(int j = i  ; j < n; j++){
            if(arr[j] - arr[i] <= d){
                maxremain = max(maxremain, j - i + 1);
            }
            else
                break;
        }
    }
    cout<< ((maxremain == -1) ? 0 : (n - maxremain))<<endl;
    return 0;
}