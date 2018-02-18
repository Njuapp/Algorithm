//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-18 09:43:17
//Last modified: 2018-02-18 09:55:47
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    for(int i = 0; i * A <= N ; i++){
        if((N-i*A)%B == 0){
            int j = (N-i*A)/B;
            for(int k = 0; k < i; k++){
                for(int m = 0; m < A; m++)
                    cout<<1+k*A+(m+1)%A<<" ";
            }
            for(int k = 0; i*A+k*B<N; k++){
                for(int m = 0; m < B; m++)
                    cout<<1+i*A+k*B+(m+1)%B<<" ";
            }
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}
