//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-16 14:04:17
//Last modified: 2018-02-16 14:36:51
#include <iostream>
#include <vector>
using namespace std;
int f(int num){
    int sum = 1;
    while(num){
        int digit = num % 10;
        num /= 10;
        sum *= digit?digit:1;
    }
    return sum;
}
int main(){
    int q;
    cin >> q;
    vector<int> vec(1,0);
    vector<vector<int> > res(10,vector<int>(1000001,0));
    for(int i = 1; i < 10; i++){
        vec.push_back(i);
        for(int j = 1; j < 10; j++){
            res[j][i] = res[j][i-1];
        }
        res[i][i] = res[i][i-1]+1;
    }
    for(int i = 10; i <= 1000000; i++){
        vec.push_back(vec[f(i)]);
        for(int j = 1; j < 10; j++){
            res[j][i] = res[j][i-1];
        }
        res[vec[f(i)]][i] = res[vec[f(i)]][i-1]+1;
    }
    while(q--){
        int l,r,k;
        cin >> l >> r >> k;
        cout<<res[k][r] - res[k][l-1]<<endl;
    }
    return 0;
}
