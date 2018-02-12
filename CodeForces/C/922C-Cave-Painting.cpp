//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-12 23:37:38
//Last modified: 2018-02-12 23:47:24
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
typedef long long int llt;
int main(){
    llt n,k;
    cin >>n >>k;
    unordered_set<int> set;
    for(int i = 1; i <= k ; i++){
        if(set.find(n%i)!=set.end()){
            cout<<"No"<<endl;
            return 0;
        }
        set.insert(n % i);
    }
    cout<<"Yes"<<endl;
    return 0;
}
