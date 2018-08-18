#include<iostream>
#include<stdio.h>
using namespace std;
/*
Red-Green Tower problem을 해결하기 위해
DD 함수를 이용해 
될수있는 모든 경우의 수를 통해 쌓을수 있는 층을 co 배열에 저장한뒤,
count()함수의 첫번째 for문에서 co배열에 저장되어있는 가장큰 층수를 height에 저장한다.
count()함수의 두번째 for문에서 co배열의 원소들중 height와 같은것을 cnt에 저장한뒤 출력하는 형식으로
가장높이 쌓을수있는 탑의 경우의수를 구했다.
*/

int r, g;//red 와 green Block 
int co[99999];//경우의수를 통해 쌓은 층을 저장하는 배열, 경우의수가 100,000 가 넘어가면 터지게된다.
int cc = 0;//배열의 index.저장할때마다 1증가

void DD(int rr, int gg, int ffl){
	/*남은 red 와 green Block의 수와 현재 층수인 ffl에 따라서
	각각의 다른 작업을 수행하도록 하였다.*/	
	co[cc] = ffl;
	cc++;
	if (ffl > rr&&ffl > gg){
		return;
	}
	if (ffl > rr&&gg > ffl)
		DD(rr, gg - ffl, ffl + 1);
	else if (ffl > gg&&rr > ffl)
		DD(rr - ffl, gg, ffl + 1);
	else if (ffl == gg || ffl == rr){
		if (ffl == gg)
		DD(rr, gg - ffl, ffl + 1);
		else if (ffl==rr)
		DD(rr - ffl, gg, ffl + 1);
	}
	if (rr > ffl && gg > ffl){
		DD(rr - ffl, gg, ffl + 1);
		DD(rr, gg - ffl, ffl + 1);
	}
}
void count(){
	int height = 0;
	for (int i = 1; i < cc; i++){//가장 높은층을 구하는 for문
		if (co[i]>height)
			height = co[i];
	}
	int cnt = 0;
	for (int i = 0; i < cc; i++){//가장높은층의 경우의수를 세는 for문
		if (co[i] == height)
			cnt++;
	}
	if (cnt == 0)
		return;
	cout << cnt;
}
void main(){
	cin >> r >> g;
	if (r == 1&&g == 1)//r와g가 모두 1일때
		cout << 2;
	else if (r == 0 && g != 0 || r != 0 && g == 0)//r 나 g 둘중하나가 0일때
		cout << 1;
	else
		DD(r, g, 1);
	count();
	/*for (int i = 0; i<cc; i++)
		cout << co[i] << "\t";*/


	cin >> cc;

}