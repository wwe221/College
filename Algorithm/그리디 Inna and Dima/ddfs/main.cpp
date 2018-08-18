#include<iostream>
#include<stdlib.h>
#include <string>  
#include<stdio.h>
using namespace std;

/*
Inna and Dima problem�� ��� �׷����� ����� ���Ҽ��ְ�,�簢�� ����� ��鼭 ��ó�� ��� ���ؽ���
���� �Ǿ��ֱ� ������
�迭�� ������ �����Ұ��̶�� �Ǵ��Ͽ�,�ִ� ����� 500,500 �� 2���� �迭�� �����Ͽ���.
���̺��� ����� n,m���� �Է��� �޴´�.
���ڸ� ����� ���� DIMA�� �Ű� ��ġ�Ѵ�.

DimaCheck �迭�� �ش� ��ǥ�� ���ؽ��� ����̳� �鷶���� Ȯ���ϱ� ���� �迭�̴�.
�ѹ��Ƿ��� �ȿ��� �ϳ��� ���ؽ��� �ι��̻� �湮�� �Ѱ�쳪 ���ѷ����� ���°��� üũ�ϱ� �����̴�.

find �Լ��� �׷��������� DFS�� �ش��ϴ� ������ �ϰ��ִ�.
����Ǿ��ִ� ���ؽ����� ���������� �´� ���ؽ��� ã���� �湮�ϴ� ������ �Ѵ�.
��ǲ�� ���D�� ���������� ����Ͽ� find�Լ��� �����ϱ� ������ 
D���� find�Լ��� ����Ǳ��� DimaCheck �Լ��� �ʱ�ȭ ��Ų��.
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