#include <cstdio>
typedef long long int ll;
int a[200000+10];
int main(){
    int n;
    scanf("%d",&n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        sum += a[i];
    }
    ll res = 0;
    for(int i = 0; i < n; i++){
        res += a[i];
        if(res >= sum / 2.0){
            printf("%d\n",i+1);
            return 0;
        }
    }
    return 0;
}
