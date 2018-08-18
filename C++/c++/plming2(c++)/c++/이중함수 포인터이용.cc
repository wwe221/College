#include<iostream>
using namespace std;

void swap(int*a,int*b,bool*c){
	int temp;
	if(*a>*b){
		temp=*a;
		*a=*b;
		*b=temp;
		*c = true;}
}

int main()
{
	int a[] = {8,21,9,4,12,3,52,20,11,5,3,1};
	int s = sizeof(a)/sizeof(a[0]);
	int f = 0;
	cout<<"befor bubble sorting:";
	for (int i = 0;i<s;++i)
		cout<<a[i]<<"\n";
	while(true){
		bool swapFlag = false;
		for (int i=0;i<s-1;++i){
				swap(&a[i],&a[i+1],&swapFlag);
				//if(a[i]>a[i+1]){				b= a[i];				a[i]=a[i+1];				a[i+1]= b;}			
			}			if(!swapFlag)
				break;}
		cout<<"After";
		for(int i= 0;i<s;++i)
			cout<<a[i]<<"\n";
		return 0 ;
	}