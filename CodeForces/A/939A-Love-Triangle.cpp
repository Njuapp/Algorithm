//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-21 13:58:05
//Last modified: 2018-02-21 14:03:56
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    vector<int> vec(1,0);
    cin>>n;
    while(n--){
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    for(int i = 1; i < vec.size();i++){
        int cur = i;
        for(int j = 0; j < 3; j++)
            cur = vec[cur];
        if(cur == i){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
