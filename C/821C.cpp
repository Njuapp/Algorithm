#include <iostream>
#include <stack>
using namespace std;
int n;
stack<int> st;
int main(int argc, const char * argv[]) {
    cin >> n;
    int exp = 1, ans = 0;
    for(int i = 0; i < 2 * n; i ++){
        string cmd;
        cin >> cmd;
        if(cmd[0] == 'a'){
            int num;
            cin >> num;
            st.push(num);
        }
        else{
            if(!st.empty()){
                if(exp == st.top()){
                    st.pop();
                }
                else{
                    ans ++;
                    while(!st.empty())
                        st.pop();
                }
            }
            exp++;
        }
    }
    cout<< ans << endl;
    return 0;
}
