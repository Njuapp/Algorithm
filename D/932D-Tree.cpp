//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-18 10:27:37
//Last modified: 2018-02-18 23:43:49
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long int llt;
int main()
{
    int Q;
    cin >> Q;
    llt last = 0;
    vector<llt> weight(2,0);
    vector<llt> parent(2,0);
    while(Q--){
        llt type, p, q;
        scanf("%lld %lld %lld", &type, &p, &q);
        llt  r = p ^ last;
        if(type == 1){
            llt w = q ^ last;
            weight.push_back(w);
            parent.push_back(r);
        }
        else{
            llt limit = q ^last;
            last = 0;
            int sum = 0;
            int last_one = 0;
            for(llt cur = r; cur ; cur = parent[cur]){
                //Check whether it is OK to add the current node.
                if(sum + weight[cur] > limit)
                    break;
                else if(last_one <= weight[cur]){
                    last_one = weight[cur];
                    last ++;
                    sum += weight[cur];
                }
            }
            printf("%lld\n",last);
        }
    }
    return 0;
}
