#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vec(n,0);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    bool unset = true;
    int col = 1;
    for(int i = 1; i < n; i++){
        if(vec[i] == vec[i-1]){
            cout<<"NO"<<endl;
            return 0;
        }
        else if(abs(vec[i] - vec[i-1]) > 1){
            if(unset){
                unset = false;
                col = abs(vec[i]-vec[i-1]);
            }
            else {
                if(col != abs(vec[i]-vec[i-1]))
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }
    if(unset){
        cout<<"YES"<<endl;
        cout<<"1 1000000000"<<endl;
    }
    else{
        for(int i = 1; i < n; i++) {
            if (abs(vec[i] - vec[i - 1]) == 1 && (vec[i] - 1) / col != (vec[i - 1] - 1) / col) {
                cout << "NO" << endl;
                return 0;
            }
        }
        cout<<"YES"<<endl;
        cout<<"1000000000 "<<col<<endl;
    }
    return 0;
}