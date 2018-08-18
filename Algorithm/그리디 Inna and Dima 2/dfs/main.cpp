#include <iostream>  
#include <cstdio>  
#include <string>  
#include <cstring>  
#include <stdlib.h>  
#include <math.h>  
#include <ctype.h>  
#include <queue>  
#include <map>  
#include <set>  
#include <algorithm>  

using namespace std;


int n, m;
int INF = n*m/2;
char mp[1001][1001], str[] = "DIMA";
int dp[1001][1001];
int jx[] = { 0, 0, 1, -1 };
int jy[] = { 1, -1, 0, 0 };


int dfs(int x, int y, int tmp)
{
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = INF;
	int i, a, b, t = 0;
	tmp = (1 + tmp) % 4;
	for (i = 0; i<4; i++)
	{
		a = x + jx[i];
		b = y + jy[i];
		if (a >= 0 && a<n&&b >= 0 && b<m&&mp[a][b] == str[tmp])
		{
			t = max(t, dfs(a, b, tmp));
		}
	}
	dp[x][y] = ++t;
	return t;
}
int main()
{
	int i, j, max1 = 0;
	cin >> n >> m;
	for (i = 0; i<n; i++)
	{
		cin >> mp[i];
	}
	memset(dp, -1, sizeof(dp));
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			if (mp[i][j] == 'D')
			{
				max1 = max(max1, dfs(i, j, 0));
			}
		}
	}
	if (max1 / 4 == 0)
	{
		puts("Poor Dima!");
	}
	else if (max1 >= INF)
	{
		puts("Poor Inna!");
	}
	else
		printf("%d\n", max1 / 4);
	return 0;
}