//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-21 15:55:14
//Last modified: 2018-02-21 18:05:56
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int llt;

int main(){
    int q;
    cin >> q;
    long long sum[500050];
    long long a[500050];
    int cur = 0;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int temp;
            cin >> temp;
            cur++;
            sum[cur] = sum[cur - 1] + temp;
            a[cur] = temp;
        }
        else{
            double ans = 0.0;
            int l = 1,r = cur - 1;
                while(r-l > 2){
                    int left_mid = l + (r - l ) / 3;
                    int right_mid = r - (r - l) / 3;
                    double left_v = (double)a[cur] - (double)(sum[left_mid] + a[cur])/(double)(left_mid + 1);
                    double right_v = (double)a[cur]  - (double)(sum[right_mid] + a[cur])/(double)(right_mid + 1);
                    if(left_v > right_v)
                        r = right_mid;
                    else
                        l = left_mid;
                }
            
                for(int s = l; s <= r; s++){
                    ans = max(ans,(double)((double)a[cur] - (double)(sum[s] + a[cur]) / (double)(s + 1)));
                }
                //global_max = max(global_max, vec[cur][0] - min_mean);
            
            printf("%.10lf\n",ans);
        }
    }
    return 0;
}
