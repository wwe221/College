#include<iostream>
using namespace std;

int manpower(int b, int n)
{ 
	int temp = 1;
	for (int i=0;i<n;++i)
		temp=temp*b;
	return temp;
}
int main()
{	
	int b , n, result;
	cin>>b>>n;
	result=manpower(b,n);
	cout<<"power("<<b<<","<<n<<")="<<result<<"\n";
	return 0;
}