#include<cstdio>  
#include<iostream>  
#include<string>  
#include<stdlib.h>
#include<cmath>
using namespace std;
/* ���ø� �̷�� 2�����迭�� �ϳ� �����, �¿�� ���Ʒ� ������ �Է��Ͽ����� ������ ������ ������ ���տ� ���� ���� �ް��.
   2�����迭���� ��������� ������ �̵��ϱ� ���� ������ ��� �𼭸������� ������ ���� ������ ����Ű�� �־���Ѵ�.
   �� �𼭸����� �ٱ����� ����Ű�� ���� �ϳ����ۿ� �����Ƿ�, �װ�쿡 ���� ���� ������ �ִٸ� NO�� ����ϰ� �ƴѰ�� YES�� ����Ѵ�.
*/
int n, m;
int city[500][500];
void init()// 2�����迭 ���� �ʱ�ȭ
{
	for (int i = 0; i < 500; i++){
		for (int j = 0; j < 500; j++)
			city[i][j] = 0;
	}
}
void main()
{
	init();
	cin >> n;//���� �� �Է�
	cin >> m;//���� �� �Է�
	for (int i = 0; i < n; i++)//�¿� �Է�
	{
		char c;
		cin >> c;
		if (c == '<'){
			for (int j = 0; j < m; j++)
				city[i][j] = city[i][j] + 1; //������ ����Ű�� ���⿡ ���� �ٸ����� �����ֹǷ� ������ �ٸ��� ������ ���� �ٸ��� �ȴ�.
		}
		else if (c == '>'){
			for (int j = 0; j < m; j++)
				city[i][j] = city[i][j] + 2;
		}
	}	
	for (int i = 0; i < m; i++){//���Ʒ� �Է�
		char c;
		cin >> c;
		if (c == 'v'){
			for (int j = 0; j < n; j++)
				city[j][i] = city[j][i] + 5;
		}
		else if (c == '^'){
			for (int j = 0; j < n; j++)
				city[j][i] = city[j][i] + 3;
		}
	}
	/*for (int i = 0; i < n; i++){
		cout << endl;
		for (int j = 0; j < m; j++){
			cout << city[i][j];
		}
	}*/
	if (city[0][0] == 4 || city[0][m - 1] == 5 || city[n - 1][0] == 6 || city[n - 1][m - 1] == 7)//�� �𼭸������� ������ ������ ���� ������ ���ϴ� ��� NO�� ����ϰ� �ƴ϶�� YES �� ����Ѵ�.
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	cin >> n;
}