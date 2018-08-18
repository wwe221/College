#include<iostream>
#include<stdlib.h>
#include <string>  
#include<stdio.h>
using namespace std;

/*
Inna and Dima problem의 경우 그래프의 사이즈를 정할수있고,사각형 모양을 띄면서 근처의 모든 버텍스와
연결 되어있기 때문에
배열로 구현이 가능할것이라고 판단하여,최대 사이즈가 500,500 인 2차원 배열로 구현하였다.
테이블의 사이즈를 n,m으로 입력을 받는다.
글자를 세기는 것을 DIMA로 옮겨 배치한다.

DimaCheck 배열은 해당 좌표의 버텍스에 몇번이나 들렀는지 확인하기 위한 배열이다.
한번의루프 안에서 하나의 버텍스에 두번이상 방문을 한경우나 무한루프를 도는것을 체크하기 위함이다.

find 함수는 그래프에서의 DFS에 해당하는 역할을 하고있다.
연결되어있는 버텍스들중 다음순서에 맞는 버텍스를 찾은후 방문하는 역할을 한다.
인풋의 모든D를 시작점으로 출발하여 find함수를 수행하기 때문에 
D에서 find함수가 시행되기전 DimaCheck 함수를 초기화 시킨다.
*/

int fin = 0;
int sum=0;
int n, m;
char DIMA[500][500];
int DimaCheck[500][500];

void init(){
	for (int i = 0; i < 500;i++)
	for (int j = 0; j < 500; j++)
		DimaCheck[i][j] = 0;
	sum = 0;
}
void find(int i, int j){
	if (DimaCheck[i][j] == 0)
		DimaCheck[i][j]++;
	else if (DimaCheck[i][j] >0){
		DimaCheck[i][j]++;		
	}
	if (DimaCheck[i][j] > n * m){
		cout << "Poor inna!" << endl;
		fin = -1;
		return;
	}
	if (DIMA[i][j] == 'D'){
		if (DIMA[i + 1][j] == 'I')
			find(i + 1, j);
		else if (DIMA[i][j + 1] == 'I')
			find(i, j + 1);
		else if (DIMA[i - 1][j] == 'I')
			find(i - 1, j);
		else if (DIMA[i][j - 1] == 'I')
			find(i, j - 1);
	}
	if (DIMA[i][j] == 'I'){
		if (DIMA[i + 1][j] == 'M')
			find(i + 1, j);
		else if (DIMA[i][j + 1] == 'M')
			find(i, j + 1);
		else if (DIMA[i - 1][j] == 'M')
			find(i - 1, j);
		else if (DIMA[i][j - 1] == 'M')
			find(i, j - 1);
	}
	if (DIMA[i][j] == 'M'){
		if (DIMA[i + 1][j] == 'A')
			find(i + 1, j);
		else if (DIMA[i][j + 1] == 'A')
			find(i, j + 1);
		else if (DIMA[i - 1][j] == 'A')
			find(i - 1, j);
		else if (DIMA[i][j - 1] == 'A')
			find(i, j - 1);
	}
	if (DIMA[i][j] == 'A'){
		sum++;
		if (sum > fin)
			fin = sum;
		if (DIMA[i + 1][j] == 'D')
			find(i + 1, j);
		else if (DIMA[i][j + 1] == 'D')
			find(i, j + 1);
		else if (DIMA[i - 1][j] == 'D')
			find(i - 1, j);
		else if (DIMA[i][j - 1] == 'D')
			find(i, j - 1);
	}
}
void main(){
	cin >> n >> m;
	char a;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a;
			DIMA[i][j] = a;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (DIMA[i][j] == 'D'){
				init();
				find(i, j);
			}
		}
	}
	
	if (fin == 0)
		cout << "Poor Dima!" << endl;
	else if (fin>0)
		cout << fin;
	cin >> a;
}