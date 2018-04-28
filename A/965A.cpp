#include <cstdio>
using namespace std;
int main(){
  int k, n, s, p;
  scanf("%d %d %d %d", &k, &n, &s, &p);
  int every = n / s;
  if(n % s)
    every ++;
  int packs = (k * every) / p;
  if((k*every) % p)
    packs++;
  printf("%d",packs);
  return 0;
}