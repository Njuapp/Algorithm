//Author: Cheng(Steve) Hang
//Contact: calvinhance@gmail.com 
//All  rights reserved.
//Site: njuapp.github.io
//Date: 2018-02-11 23:48:40
//Last modified: 2018-02-12 00:38:52
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
int main(){
    int cnt;
    cin >>cnt;
    unordered_map<int,int> vec;
    for(int i =0; i < cnt; i++){
        int n;
        cin>>n;
        if(vec.find(n) != vec.end())
            vec[n] ++;
        else
            vec[n] = 1;
    }
    long long int res = 0;
    for(auto it = vec.begin(); it != vec.end(); it++){
        long long int max = pow(10,9) ;
        for(long long int j = 2; j <= 2 *max; j*=2)  
            
            if(vec.find(j-it->first)!= vec.end()){
                if( j/2!= it->first)
                    res+=it->second*vec[j-it->first];
                else 
                    res+= (long long int)it->second *(it->second - 1);
            }
    }
    cout<<res/2<<endl;
    return 0;
}
