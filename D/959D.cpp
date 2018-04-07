//
// Created by 杭诚 on 2018/4/6.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;
set<int> s;
vector<int> decomp[2000005];
int p[2000005];
int er[2000005];
using namespace std;
int main()
{

    int n;
    cin >> n;
    for(int i = 2; i < 2000005; i++){
        if(!p[i]) {
            for (int k = i; k < 2000005; k += i) {
                decomp[k].push_back(i);
                p[k] = 1;
            }
        }
        s.insert(i);
    }
    bool adjusted = false;
    while(n--){
        int tmp;
        cin >> tmp;
        if(s.empty()){
            cout<<"FUCK";
        }
        int it = *s.begin();
        if(!adjusted){
            it = *s.lower_bound(tmp);
            if(it != tmp){
                adjusted = true;
            }
        }
        for(int comp: decomp[it]){
            for(int k = comp; k < 2000005; k+= comp)
            {
                if(!er[k]){
                    s.erase(k);
                    er[k] = 1;
                }
            }
        }
        cout<<it<<" ";
    }
    return 0;
}
