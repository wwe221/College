#include<iostream>
#include<cmath>
#include<string>
#include<stdlib.h>
using namespace std;

int n, m;
bool city[500][500];

int g(int x, int y)
{
	return (x - 1)*m + y;
}
void main()
{	
	cin >> n;
	cin >> m;
	
	for (int i = 1; i <= n; i++)//좌우 입력
	{
		char ch = getchar();

		while (ch != '>'&&ch != '<')
			ch = getchar();
		for (int j = 1; j < m; j++){
			if (ch == '>')
				city[g(i, j)][g(i, j + 1)] = 1;
			else
				city[g(i, j + 1)][g(i, j)] = 2;
		}
	}
	cout << endl << endl;
	for (int i = 1; i <= m; i++)//위아래 입력
	{
		char ch = getchar();

		while (ch != '^'&&ch != 'v')
			ch = getchar();

		for (int j = 2; j <= n; j++)
			if (ch == '^') 
				city[g(j, i)][g(j - 1, i)] = 5;
			else 
				city[g(j - 1, i)][g(j, i)] = 3;
	}
	
	int sum = n*m;
	for (int k = 1; k <= sum; k++)
		for (int i = 1; i <= sum; i++)
			for (int j = 1; j <= sum; j++)
				city[i][j] = city[i][j] || (city[i][k] && city[k][j]);
	for (int i = 1; i <= sum; i++)
		for (int j = 1; j <= sum; j++)
			if (i != j&&!city[i][j])
		{
			cout <<"NO";
			return;
		}
	cout<<"YES";
	return;
}