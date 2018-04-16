#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    string str;
    cin >> str;
    if(str.length()<26)
    {
        cout<<-1<<endl;
        return 0;
    }
    char ch = 'a';
    for(int i = 0; i < str.length(); i++){
        if(str[i] <= ch){
            str[i] = ch;
            ch ++;
            if(ch > 'z')
                break;
        }
    }
    if(ch <= 'z')
        cout<<-1<<endl;
    else
        cout<<str<<endl;
    return 0;
}