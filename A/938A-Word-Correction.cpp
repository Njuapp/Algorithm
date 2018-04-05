//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-22 14:13:20
//Last modified: 2018-02-22 14:31:11
#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isVowel(char ch){
    return ch == 'a'||ch == 'e'||ch=='i'||ch=='o'||ch=='u'||ch == 'y';
}
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    string res = "";
    while(i<n){
        if(!isVowel(s[i])){
            res+= s[i];
            i++;
        }
        else{
            res+= s[i];
            i++;
            while(i<n&&isVowel(s[i]))
                i++;
        }
    }
    cout<<res<<endl;
    return 0;
}
