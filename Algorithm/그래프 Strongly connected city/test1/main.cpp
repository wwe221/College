#include<cstdio>  
#include<iostream>  
#include<string>  
#include<stdlib.h>
#include<cmath>
using namespace std;
/* 도시를 이루는 2차원배열을 하나 만들고, 좌우와 위아래 방향을 입력하였을때 각각이 가지는 방향의 조합에 따라 값을 메겼다.
   2차원배열에서 모든점에서 모든곳을 이동하기 위한 조건은 모든 모서리에서의 방향이 도시 안쪽을 가리키고 있어야한다.
   각 모서리에서 바깥쪽을 가리키는 경우는 하나씩밖에 없으므로, 그경우에 따른 값을 가지고 있다면 NO를 출력하고 아닌경우 YES를 출력한다.
*/
int n, m;
int city[500][500];
void init()// 2차원배열 도시 초기화
{
	for (int i = 0; i < 500; i++){
		for (int j = 0; j < 500; j++)
			city[i][j] = 0;
	}
}
void main()
{
	init();
	cin >> n;//세로 수 입력
	cin >> m;//가로 수 입력
	for (int i = 0; i < n; i++)//좌우 입력
	{
		char c;
		cin >> c;
		if (c == '<'){
			for (int j = 0; j < m; j++)
				city[i][j] = city[i][j] + 1; //각각이 가리키는 방향에 따라 다른수를 더해주므로 조합이 다르면 가지는 값이 다르게 된다.
		}
		else if (c == '>'){
			for (int j = 0; j < m; j++)
				city[i][j] = city[i][j] + 2;
		}
	}	
	for (int i = 0; i < m; i++){//위아래 입력
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
	if (city[0][0] == 4 || city[0][m - 1] == 5 || city[n - 1][0] == 6 || city[n - 1][m - 1] == 7)//각 모서리점들이 가지는 방향이 도시 밖으로 향하는 경우 NO를 출력하고 아니라면 YES 를 출력한다.
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	cin >> n;
}