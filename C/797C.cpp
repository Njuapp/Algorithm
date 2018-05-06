#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<char,int> pci;
int main()
{
	string str;
	cin >> str;
	int top = 0;
	int min = str[0];
	for(int i = 1; i < str.length(); i++){
		if(str[i] < min){
			min = str[i];
			top = i;
		}
	}
	string ans;
	vector<bool> out(str.length(), false);
	while(top != str.length() - 1){
		ans.push_back(str[top]);
		out[top] = true;
		int temp = top + 1;
		for(int i = top - 1; i >=0; i--){
			if(!out[i]){
				top = i;
				break;
			}
		}
		int next_min = INT_MAX;
		if(!out[top])
			next_min = str[top];
		for(; temp < str.length(); temp ++){
			if(str[temp] < next_min){
				next_min = str[temp];
				top = temp;
			}
		}
	}
	for(int j = str.length()-1; j >=0; j--){
		if(!out[j])
			ans.push_back(str[j]);
	}
	cout<<ans;
    return 0;
}