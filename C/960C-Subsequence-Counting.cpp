#include <iostream>
#include <vector>
using namespace std;
int n,d,t;
long long x=1;
vector <long long> v;
int main()
{
	cin>>n>>d;
	while (n)
	{
		if (n>=(1<<t))
		{
			n-=(1<<t);
			t++;
			v.push_back(x);
			continue;
		}
		cout<<t<<endl;
		t=0;
		x+=d;
	}
	cout<<v.size()<<'\n';
	for (auto &c:v) cout<<c<<' ';
	return 0;
}