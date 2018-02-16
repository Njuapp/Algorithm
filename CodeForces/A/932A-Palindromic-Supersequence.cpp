//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-16 13:56:00
//Last modified: 2018-02-16 13:58:57
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string str;
    cin >> str;
    cout<<str;
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    return 0;
}
