//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-21 14:05:51
//Last modified: 2018-02-21 14:16:10
#include <iostream>
#include <vector>
using namespace std;
typedef long long int llt;
int main(){
    llt N;
    int K;
    cin>>N>>K;
    vector<llt> vec(1,0);
    while(K--){
        llt temp;
        cin >> temp;
        vec.push_back(temp);
    }
    int idx = 0;
    llt max = 0;
    for(int i = 1; i < vec.size(); i++){
        llt cap = N - N % vec[i];
        if(cap > max){
            max = cap;
            idx = i;
        }
    }
    if(idx == 0){
        cout<<1<<" "<<0<<endl;
        return 0;
    }
    cout<<idx<<" "<<N/vec[idx]<<endl;
    return 0;
}
