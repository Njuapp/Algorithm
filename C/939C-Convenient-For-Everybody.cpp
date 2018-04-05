//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-21 14:17:13
//Last modified: 2018-02-21 14:48:37
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> vec(n+1,0);
    for(int i = 1; i <= n; i++)
        cin >> vec[i];
    int s, f;
    cin >> s >>f;
    int sum = 0;
    for(int k = s; k < f; k++)
        sum+= vec[k];
    int sum1 = sum;
    int first = s;
    int last = f;
    int max = sum;
    int idx = 1;
    for(int m = n; m >= 2; m--){
        int minus = first % n == 0 ? n : first % n;
        int plus = last % n == 0 ? n : last % n;
        sum += (vec[plus] - vec[minus]);
        first++;
        last ++;
        if(sum >= max){
            max = sum;
            idx = m;
        }
    }
    cout<<(sum1==sum?1:idx)<<endl;
    return 0;
}
