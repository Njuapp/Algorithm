//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-13 23:23:23
//Last modified: 2018-02-13 23:37:08
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        //vector<pair<int,int>> vec;
        //queue<int, 
        vector<int> res;
        int time = 1;
        for(int i =0; i < n; i++){
            int come, leave;
            cin >> come >> leave;
            //vec.push_back(make_pair(come, leave));
            if(leave < time){
                //leave
                res.push_back(0);
            }
            else{
                //get served
                res.push_back(max(come, time));
                //time passed by one moment
                time = max(come, time) + 1;
            }
        }
        for(int ele: res)
            cout << ele <<endl;
    }
    return 0;
}
