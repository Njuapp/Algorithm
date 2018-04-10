/*
 * Author: Cheng Hang on 04/10/2018
 * All Copyrights Reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

typedef long long int lli;
using namespace std;
int min_val(vector<lli> a, int i){
    return *min_element(a.begin()+i-4, a.begin()+i+1);
}
int max_val(vector<lli> a, int i){
    return *max_element(a.begin()+i-4, a.begin()+i+1);
}
int main(){
    lli n;
    cin >> n;
    vector<lli> a(n);
    string b(n,'0');
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    int l = - 1000000000,r = 1000000000;
    for(int i = 4; i < n; i++){
        if(b[i] == '0' && b[i-1] == '1'){
            r = min(r, min_val(a,i) - 1);
        }
        else if(b[i] == '1' && b[i-1] == '0'){
            l = max(l, max_val(a,i) + 1);
        }
    }
    cout<< l <<" "<<r<<endl;
    return 0;
}