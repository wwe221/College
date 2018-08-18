#include<iostream>
using namespace std;
int main()
{
	char in[21];
	char* x=&in[0];
	char out[21];
	char* y=&out[0];
	int n=0;
	int i =0;
	int a =0;
	char z = '\0';
	cout << "문자를 쓰시오 : ";
	cin >> in;
	while (true){
		if(*(x+n)==z)
			break;
		n=n+1;}
	cout <<"\n"<<"글자"<<n<<"개\n";
	while(i<n){
		*(y+i)=*(x+n-i-1);
		i=i+1;}
	cout<<"\n";
	while(a<n){
		if(*(x+a)!=*(y+a)){
			cout << *(x+a) <<"\t"<<*(y+a)<<"\t\n회문이 아닙니다.\n";
			break;}
		cout << *(x+a) <<"\t"<<*(y+a)<<"\n";
		if(a==n-1)
			cout <<"회문입니다."<<"\n";
		a=a+1;}
	return 0;
}