#include<iostream>
using namespace std;



int mymax(int a,int b){
	
	if(a>b)
		return a;
	else
		return b;
	}
int mymin(int a,int b){
	
	if(a>b)
		return b;
	else
		return a;
}							//������ ��ſ� ���۷��� ������ ���
void my_max_min(int a,int b,int& pmaxv,int& pminv){
	pmaxv = mymax(a,b);
	pminv = mymin(a,b);
	}

int main(){
	int maxv ;
	int minv ;
	my_max_min(4,5,maxv,minv);	
	cout <<maxv<<"\n"<<minv;
	return 0;
	}