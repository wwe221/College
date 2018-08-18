#include<iostream>
using namespace std;

void someth(int a)
{	
	if(a==0)
		return;
	else
		someth(a/2);
		cout<<a%2;	
}
int main(){
	int n;
	cin>>n;
	someth(n);
	return 0;
}
