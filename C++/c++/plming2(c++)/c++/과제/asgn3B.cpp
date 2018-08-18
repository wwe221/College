#include<iostream>
using namespace std;
int b;
int sum(int a)
	{	
		if(a==0)
			return b;
		else{
			b=b+a;
			cout<<"a="<<a<<"\tsum="<<b<<"\n";
			sum(a-1);}}
int main(){
	int result = sum(10);
	cout<< result;
}