#include<stdio.h>
#include<iostream>
using namespace std;

/* 그리디 알고리즘을 Table decorations problem에 이용하려면,
가장많이 가지고 있는 색 풍선을 먼저 2개 사용하고, 2번째로 많은 색의 풍선을 1개 사용하므로서
가장 적은 수로 가지고있는 색의 풍선을 아끼는 것이다.
풍선의 수를 B배열에 집어 넣는다.
하지만 가지고있는 풍선의 수의 정도가 테이블을 하나 꾸밀때마다 바뀌므로
greedy() 함수를 수행할때마다 sorting을 수행해서 갖고있는 풍선의 수를 오름차순으로 정렬한다.
그 결과 B[2]에 가장 큰 수의 색,B[0]엔 가장 작은 수의 색이 들어가게 된다.
main 함수의 while문 안의 greedy함수가 돌아가면서 풍선의 수가 들어가있는 B배열의 모든합이 3보다 적게되면 while문이 종료되면서 
꾸민 테이블의 수를 출력한다.
하지만 만약 하나의 풍선만 3개가 있는경우 (input이 3 0 0 일 경우) 테이블을 꾸밀수 없으므로 while문을 빠져 나간다.
*/

int B[3];
int table = 0;

void sorting(){
	int a;
	for(int i=0;i<2;i++){
		if(B[i]>B[i+1]){
			a=B[i];
			B[i]=B[i+1];
			B[i+1]=a;
		}
	}
}
void greedy(){
	sorting();
	B[2]=B[2]-2;
	B[1]=B[1]-1;
	table++;
}
void main(){
	for(int i=0;i<3;i++){
		cin>>B[i];
	}
	int lim;
	sorting();
	while(1){
		if(B[0]==0&&B[1]==0){
			break;
		}
		greedy();
		if(B[0]+B[1]+B[2]<3)
			break;
	}

	cout<< table;
	cin >> lim;
}
