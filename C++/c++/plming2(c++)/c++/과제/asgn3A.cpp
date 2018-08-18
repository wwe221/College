#include<iostream>
using namespace std;
int midvalue(int a, int b, int c , int d, int e)
{	int mid=(a+b+c+d+e)/5;
int midd[]={a,b,c,d,e};
int NumOfStd = 4;
	int f = 0;
	while(f<NumOfStu){
	int i = 0;
	int b = 0;
	while(i<NumOfStd-1){
		if(students[i-1].sum>students[i.sum]){
			b= students[i-1];
			students[i-1]=students[i];
			students[i]= b;}
		i++;}
		f++;}
	return midd[2];}

void Midvalue_P(int a, int b, int c, int d ,int e,int*p)
{
	*p=midvalue(a,b,c,d,e);
}
void Midvalue_R(int a, int b, int c, int d ,int e,int&p)
{p=midvalue(a,b,c,d,e);}


int main(){
	int mid = midvalue(9, 1, 15, 3, 7);
	int mid1, mid2;;
	Midvalue_P(9,1,15,3,7,&mid1);
	Midvalue_R(9,1,15,3,7,mid2);
	cout<< "mid="<<mid<<"\t"<<"&mid1="<<mid1<<"\t"<<"mid2="<<mid2;
	return 0;}