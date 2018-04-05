#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <map>

typedef long long int llt;
typedef std::pair<llt,llt> pii;
using namespace std;
bool inaline(pii a, pii b, pii c){
    return (a.second - b.second)*(c.first - b.first) == (a.first - b.first)*(c.second - b.second);
}
vector<pii> pairs;
bool aline(int mode){
    vector<pii> remain;
    if(mode == 1)
        swap(pairs[1], pairs[2]);
    else if(mode == 2)
        swap(pairs[0], pairs[2]);
    for(int i = 2; i < pairs.size(); i++){
        if(!inaline(pairs[0],pairs[1],pairs[i]))
            remain.push_back(pairs[i]);
    }
    if(remain.size()<=2)
    {
        return true;
    }
    bool flag = true;
    for(int i = 2; i < remain.size(); i++){
        if(!inaline(remain[0],remain[1],remain[i]))
        {
            flag = false;
            break;
        }
    }
    return flag;
}
int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        llt x, y;
        cin >> x >> y;
        pairs.push_back(make_pair(x,y));
    }
    if(n <= 3)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    for(int mode = 0; mode < 3; mode++){
        if(aline(mode))
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}