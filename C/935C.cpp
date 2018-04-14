//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-04-12 23:39:54
//Last modified: 2018-04-14 01:40:22
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    double R, x, y, x1, y1;
    cin >> R >> x >> y >> x1 >> y1;
    double dist = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
    if(dist >= R){
        printf("%.15lf %.15lf %.15lf", x,y,R);
        return 0;
    }
    if(dist == 0){
        printf("%.15lf %.15lf %.15lf", x+R/2, y, R/2);
        return 0;
    }
    double cos = (x-x1)/dist;
    double sin = (y-y1)/dist;
    double x2 = x + cos * (R - dist) / 2;
    double y2 = y + sin * (R - dist) / 2;
    printf("%.15lf %.15lf %.15lf",  x2, y2, (R+dist)/2);
    return 0;
}
