#include<iostream>
using namespace std;
int main()
{
	char out[21];
	char in[21];
	int n=0;
	int i =0;
	int a =0;
	char z = '\0';
	cout << "문자 : ";
	cin >> in;
	while (true){
		if(in[n]==z)
			break;
		n=n+1;}
	while(i<n){
		out[i]=in[n-i-1];
		i=i+1;
	}
	cout<<"\n";
	while(a<n){
		if(in[a]!=out[a]){
			cout <<in[a] <<"\t"<<out[a]<<"Wrong\n회문이 아닙니다.\n";
			break;
		}
		cout <<in[a] <<"\t"<<out[a]<<"\n";
		if(a==n-1)
			cout <<"회문입니다."<<"\n";
		a=a+1;
	}
	return 0;
}