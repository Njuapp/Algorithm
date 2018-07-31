#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
#define rep(i,n) for(int i = 0; i < (n); i ++)
int n;
LL nums[200005];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= 2 * n; i ++){
        cin >> nums[i];
    }
    sort(nums + 1, nums + 2 * n + 1);
    LL mini = INT_MAX;
    for(int i = 2; i <=  n; i ++){
        mini = min(mini, nums[i+n-1] - nums[i]);
    }
    LL res1 = (nums[2 * n] - nums[1]) * mini;
    LL res2 = (nums[2 * n] - nums[n+1]) *(nums[n] - nums[1]);
    cout<<min(res1, res2)<<endl;
    return 0;
}