//Author: Cheng(Steve) Hang
//Contact: calvinhance@gmail.com 
//All  rights reserved.
//Site: njuapp.github.io
//Date: 2018-02-11 22:04:29
//Last modified: 2018-02-11 22:23:46
#include <iostream>
#include <vector>
using namespace std;
void isPrime(int n){
    bool* arr = new bool[n+1]; 
    for(int i = 0; i <= n; i++)
        arr[i] = false;
    arr[0]=arr[1]=arr[2]=false;
    for(int j = 2; j <= n; j++){
        for(int k = 2; k * j <= n; k++){
            arr[k*j] = true;
        }
    }
    for(int i =1; i <= n / 2;i++){
        if(arr[i] && arr[n - i]){
            cout<<i<<" "<<n-i<<endl;
            return;
        }
    }
}
int main(){
    int n;
    cin >>n;
    if(n %2 == 0)
        cout<<4<<" "<<n-4<<endl;
    else
        isPrime(n);
    return 0;
}
