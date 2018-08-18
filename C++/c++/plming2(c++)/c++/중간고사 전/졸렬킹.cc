#include<iostream>
using namespace std;
int main()
{
	int a[] = {8,21,9,4,12,3,52,20,11,5,3,1};
	
	int s = 11;
	int f = 0;
	while(f<12){
	int n = 0;
	int b = 0;
	while(n<s){
		if(a[n]>a[n+1]){
			b= a[n];
			a[n]=a[n+1];
			a[n+1]= b;}
		n++;}
		f++;}	
	int c = 0;
	while(c<s+1){
	cout<<a[c]<<"\n";
	c++;}
	
	return 0;
	}