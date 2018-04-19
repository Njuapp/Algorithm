#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;
const int maxn = 100;
set<int> s;
int main(){
    int n;
    scanf("%d", &n);
    int tmp;
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if(tmp)
            s.insert(tmp);
    }
    printf("%d", s.size());
    return 0;
}