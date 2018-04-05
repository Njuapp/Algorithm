//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-13 00:00:57
//Last modified: 2018-02-13 00:36:18
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long int llt;
int cnt(string s){
    int sum = 0;
    for(auto k:s){
        if(k=='s')
            sum++;
    }
    return sum;
}
llt noise(string s){
    llt sum = 0;
    int sn = 0;
    for(auto k:s){
        if(k=='s')
            sn++;
        else
            sum+=sn;
    }
    return sum;
}
int main(){
    int n;
    cin >> n;
    vector<string> vecs;
    int sumh = 0;
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        vecs.push_back(tmp);
        sumh += cnt(tmp);
    }
    sort(vecs.begin(),vecs.end(),[sumh](string s1, string s2){
            return noise(s1+s2)>noise(s2+s1);
            });

    string s ="";
    for(string m: vecs)
        s+=m;
    cout<<noise(s)<<endl;
    return 0;
}
