//Author: Cheng(Steve) Hang
//Contact: calvinhance@gmail.com 
//All  rights reserved.
//Site: njuapp.github.io
//Date: 2018-02-12 21:45:09
//Last modified: 2018-02-12 21:50:03
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int x, y;
    cin >> x>>y;
    if(y<1){
        cout<<"No"<<endl;
        return 0;
    }
    else if(y==1&&x>0){
        cout<<"No"<<endl;
        return 0;
    }
    if(x-y+1>=0 &&(x-y+1)%2==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}

