//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-22 14:53:45
//Last modified: 2018-02-22 16:07:32
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)

void solve(){
    int x;
	scanf("%d", &x);
	for (int n = 1; n == 1 || n * n - (n / 2) * (n / 2) <= x; ++n){
		int lk = n * n - x;
		if (lk < 0) continue;
		int sq =sqrt(lk);
        if(sq == 0 || sq * sq != lk) continue;

		int k = n / sq;
		if (k > 0 && n / k == sq){
			printf("%d %d\n", n, k);
			return;
		}
	}

	puts("-1");
}

int main() {
    int tc;
    scanf("%d", &tc);
	forn(i, tc)
	    solve();
}        
