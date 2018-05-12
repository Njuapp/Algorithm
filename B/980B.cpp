#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <queue>
#include <bitset>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
int n,k;
int arr[4][100];
void print(){
    cout<<"YES"<<endl;
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < n; j ++){
            if(arr[i][j]==1)
                cout<<'#';
            else
                cout<<'.';
        }
        cout<<endl;
    }
}
int main() {
    cin >> n >> k;
    if(k <= n - 3){
        for(int i = 0; i < k/2; i++){
            arr[1][i+1] = arr[1][n-2-i] = 1;
        }
        if(k%2)
            arr[1][n/2]=1;
        print();
        return 0;
    }
    else{
        for(int i = 0; i < (n - 3)/2; i++){
            arr[1][i+1] = arr[1][n-2-i] = 1;
        }
        for(int i = 0; i< (k-(n-3))/2; i++){
            arr[2][i+1] = arr[2][n-2-i] = 1;
        }
        if(k%2)
            arr[1][n/2]=1;
        else if(k == 2*(n-2))
            arr[1][n/2] = arr[2][n/2]=1;
        print();
        return 0;
    }

    return 0;
}
close