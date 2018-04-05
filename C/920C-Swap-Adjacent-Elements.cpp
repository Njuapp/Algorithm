//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-13 23:46:40
//Last modified: 2018-02-14 00:21:36
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> vec(n,0);
    for(int i = 0; i < n ;i ++ )
        cin >> vec[i];
    string swap;
    cin >> swap;
    int first = 0;
    while(1){
       first = swap.find_first_of('1',first);
       if(first == string::npos)
           break;
       int last = swap.find_first_of('0',first);
       if(last == string::npos)
           last = vec.size()-1;
       sort(vec.begin()+first, vec.begin()+last+1);
       first = last;
    }
    if(is_sorted(vec.begin(), vec.end()))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
