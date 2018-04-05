//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-22 14:35:06
//Last modified: 2018-02-22 14:51:56
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> vec(n+2,1);
    for(int i = 1; i <= n; i++)
        cin >> vec[i];
    vec[n+1] = pow(10,6);
    int mingap = INT_MAX;
    for(int i = 0; i <= n ; i++){
        int gap = max(vec[n+1] - vec[i+1], vec[i] - vec[0]);
        if(mingap > gap){
            mingap = gap;
        }
    }
    cout<<mingap<<endl;
    return 0;
}
