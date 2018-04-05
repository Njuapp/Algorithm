//Author: Cheng(Steve) Hang
//Contact: calvinhance@gmail.com 
//All  rights reserved.
//Site: njuapp.github.io
//Date: 2018-02-12 21:51:46
//Last modified: 2018-02-12 23:28:44
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum = 0;
    for(int i = 1;i <=n ;i++)
        for(int j = i; j <= n; j++){
            int k = i ^ j;
            if(k >= j && k <= n && k < i + j)
                sum++;
        }
    cout<<sum<<endl;
    return 0;
}
