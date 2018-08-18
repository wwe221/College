#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/* 원활한 계산을 위해 분할정복함수에서 m값을 e-1로 지정하였습니다.
10진수로 변환한 후의 값이int 가 가질수있는
8자리 이상(16진수의 경우 5F5E100) 이 되면 정확한 계산이 되지않는 함수입니다.*/

int final(int a, int b);//리턴값 계산 함수
int cnt(char a);//몇자린지 세는 함수
int Dnc(char a[],int s,int e);//분할정복 함수

int numb = 0; //몇진수or 원소 몇개
int hm = 0;	  //몇자리수
int sum = 0; // 몇개의 암호	
char *ele;//원소배열

void main(){	
	char **pwd;	// 분석할 암호들을 넣을 배열 생성
	ifstream fcin("password.txt");
	fcin >> numb;
	fcin >> hm;
	ele = new char [numb];
	 // 암호원소들을 넣을 배열 생성
	for (int i = 0; i < numb; i++){
		fcin >> ele[i]; // 원소들을 배열에 넣음
	}
	fcin >> sum;
	pwd = new char*[sum];//총 sum개의 암호들을 넣을 배열 생성
	for (int i = 0; i < sum; i++)
		pwd[i] = new char[hm];
	for (int i = 0; i < sum; i++)//배열에 암호 삽입
		for (int j = 0; j < hm; j++)
			fcin >> pwd[i][j];
	for (int i = 0; i < sum; i++){//암호 확인
		cout<<i+1<<"번째 암호:	";
		for (int j = 0; j < hm; j++)
			cout << pwd[i][j];
		cout <<"\n";
	}
	for(int i=1;i<=sum;i++)//최종 출력
		cout<<i<<"번 암호는  "<<Dnc(pwd[i-1],0,hm-1)+1<<"번째 입니다\n";
	
	cin >> hm;
}
int Dnc(char a[],int s,int e){/*분할정복 함수(hm자리의 암호를 하나가 남을때까지 
							  분할한 다음, 가장왼쪽값에numb{진수}를 곱한다음 오른쪽값과
							  더하는 계산과정을 하는 함수입니다).*/
	int m,L,R;
	if( s==e)
		return cnt(a[s]); //값이 하나만 남을경우 그값을 계산하여서 리턴합니다.
	m = e-1;
	L = Dnc(a,s,m);
	R = Dnc(a,m+1,e);
	return final(L,R);
}
int final(int a, int b){//리턴값 계산 함수
	return (a*numb+b);
}
int cnt(char a){//암호 하나의 값 계산(암호의 자리값을 10진수로 계산한값 리턴)
	int rtn=0;
	for(int i=0;i<numb;i++)
		if(a==ele[i]){
			rtn=i;
			break;}
	return rtn;
}