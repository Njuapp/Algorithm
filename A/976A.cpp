#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
char str[110];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    int ones = 0, zeros = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == '1')
            ones++;
        else
            zeros++;
    }
    if(ones == 0)
        printf("0");
    else{
        printf("1");
        for(int i = 0; i < zeros; i++)
            printf("0");
    }
    return 0;
}