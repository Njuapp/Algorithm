//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-13 22:38:25
//Last modified: 2018-02-13 23:13:34
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int last = 0;
        int maxtime  = 0;
        k++;
        while(k--){
            int temp = n + 1;
            if(k != 0)
                cin >> temp;
            int times = ((last == 0) || (k == 0))? temp - last: 1 + (temp - last)/ 2;
            maxtime = max(times, maxtime);
            last = temp;
        }
        cout<<maxtime<<endl;
    }
    return 0;
}

