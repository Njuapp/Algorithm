#include <iostream>
#include <cstdio>
#include <vector>
#include <assert.h>
using namespace std;

const int N = 200 * 1000 + 9;

int n;
int a[N];
int f[N];
vector <int> v[N];

void upd(int pos, int d){
    for(; pos < N; pos += (pos & -pos))
        f[pos] += d;
}

int get(int pos){
    int res = 0;
    for(; pos > 0; pos -= (pos & -pos))
        res += f[pos];
    return res;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
    }

    for(int i = 1; i <= n; ++i){
        if(a[i] < N)
            v[a[i]].push_back(i);
        upd(i, 1);
    }

    long long res = 0;
    for(int i = 1; i <= n; ++i){
        int to = min(N - 1, a[i]);
        res += get(to);
        for(auto x : v[i])
            upd(x, -1);
    }

    for(int i = 1; i <= n; ++i)
        if(i <= a[i])
            --res;
    cout<< res / 2 << endl;
}