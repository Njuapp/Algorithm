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
int main() {
    string s;
    cin >> s;
    int o = 0;
    int l = 0;
    for(int i = 0;i < s.length(); i++){
        if(s[i] == 'o')
            o++;
        else
            l++;
    }
    if(o==0||l%o==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}