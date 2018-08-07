#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> dist(4, vector<int>(2,0));
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++) {
                char ch;
                cin >> ch;
                int tmp = 0;
                if(ch == '1')
                    tmp = 1;
                if(abs(k - j)%2 == 1)//dist[i][1] ++ if tmp == 1, dist[i][0]++ if tmp == 0
                    dist[i][tmp] ++;
                else
                    dist[i][1 - tmp] ++;
            }
        }

    }
    int mini = INT_MAX;
    for(int i = 0; i < 4; i++){
        for(int j = i+1; j < 4; j++){
            mini = min(mini, dist[i][0]+dist[j][0] - dist[i][1] - dist[j][1]);
        }
    }
    mini += (dist[0][1] + dist[1][1] +dist[2][1] + dist[3][1]);
    cout << mini<<endl;
    return 0;
}