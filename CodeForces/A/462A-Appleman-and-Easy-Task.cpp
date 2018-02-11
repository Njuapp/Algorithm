//Author: Cheng(Steve) Hang
//Contact: calvinhance@gmail.com 
//All  rights reserved.
//Site: njuapp.github.io
//Date: 2018-02-11 22:37:33
//Last modified: 2018-02-11 23:32:58
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >>n;
    vector<vector<int> > mat(n+2, vector<int>(n+2,0));
    vector<vector<int> > work(n+2, vector<int>(n+2,0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char ch;
            cin>>ch;
            if(ch=='o')
                mat[i][j] = 1;
            else
                mat[i][j] = 2;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = -1; k <= 1; k++){
                if(mat[i][j] == 1){
                    work[i+k][j]++;
                    work[i][j+k]++;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(work[i][j] % 2 == 1){
                cout<<"NO"<<endl;
                return 0; 
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
