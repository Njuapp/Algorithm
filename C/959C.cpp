//
// Created by 杭诚 on 2018/4/6.
//
#include <iostream>
using namespace std;
void work(int n ){
    cout<<"1 3"<<endl;
    cout<<"1 2"<<endl;
    cout<<"2 4"<<endl;
    cout<<"2 5"<<endl;
    cout<<"1 6"<<endl;
    for(int k = 7; k <= n; k++){
        if(k%2)
            cout<<"2 "<<k<<endl;
        else
            cout<<"1 "<<k<<endl;
    }
}
int main()
{
    int n;
    cin >> n;

    if(n<=5){
        cout<<"-1"<<endl;
    }
    else{
        work(n);
    }
    for(int i = 2; i <= n; i++){
        cout<<"1 "<<i<<endl;
    }
    return 0;
}
