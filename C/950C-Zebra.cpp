#include <map>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;
typedef long long ll;
const int maxn = 200010;
char s[maxn];
vector<int> shit[maxn];
int main(){
    scanf("%s", s);
    int cnt = 0;
    int ans = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '0'){
            shit[++cnt].push_back(i+1);
        }
        else{
            if(cnt == 0){
                puts("-1");
                return 0;
            }
            shit[cnt--].push_back(i+1);
        }
        ans = max(ans, cnt);
    }
    if(ans != cnt){
        puts("-1");
        return 0;
    }
    printf("%d\n", ans);
    for(int i = 1; i <= ans; i++){
        printf("%lu ", shit[i].size());
        for(int j = 0; j < shit[i].size(); j++)
            printf("%d ", shit[i][j]);
        printf("\n");
    }
}
/*
int shit[maxn];
int sz[maxn];
int main(){
    string s;
    cin >> s;
    int cur = 0;
    int szi = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '2')
            continue;
        if(s[i] == '1')
        {
            printf("-1");
            return 0;
        }
        int j = i;
        char tofind = '1';
        s[j] = '2';
        int len = 0;
        while(j >= 0 && j < s.length()){
            shit[cur + len] = j;
            len++;
            j = s.find_first_of(tofind, j);
            tofind = (tofind == '0')? '1':'0';
        }
        if(tofind == '1'){
            len --;
        }
        for(int i = 0; i < len; i ++){
            int ind = shit[cur + i];
            s[ind] = '2';
        }
        cur += len;
        sz[szi++] = len;
    }
    int poi = 0;
    printf("%d\n", szi);
    for(int i = 0; i < szi; i ++){
        printf("%d ", sz[i]);
        for(int j = 0; j < sz[i]; j ++){
            printf("%d ", 1+shit[poi+j]);
        }
        poi += sz[i];
        printf("\n");
    }
    return 0;
}
 */