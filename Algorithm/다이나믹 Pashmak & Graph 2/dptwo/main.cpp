#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int save[5000],from[5000],to[5000];//from은 엣지의 시작V , to는 엣지의 도착V.
int n,m;//입력받는값 n,m
int output;//최종적으로 계산될 output

struct Edge
{
	int bef,aft,wei;	
}E[5000];
bool cmp(struct Edge a, struct Edge b)
{
	return a.wei<b.wei;
}
void Cmp(int &a,int b)//a와 b를 비교해서 더큰걸 a에 넣는다.
{
	if(a>b)
		a=a;
	else 
		a=b;
}
void DP(int mm){
	int cnt;
	for(int i=0;i<mm;i++){
		from[0] = save[E[i].bef]+ 1;
		cnt =1;
		to[0] = E[i].aft;//천번째로 엣지를 받는 vertex
		for (; E[i].wei == E[i + 1].wei; i++){
			from[cnt] = save[E[i + 1].bef] + 1;//시작점들 값넣기			
			to[cnt++] = E[i + 1].aft;//도착점들 값넣기
		}
		while (cnt>=0){//뒤쪽에서 부터
			cnt--;//cnt 0까지
			Cmp(save[to[cnt]],from[cnt]);//save[도착V]와 시작V[]를 비교해서 save에 저장한다.
		}
	}
}
int main()
{	
	cin >> n >> m;
	for (int i=0;i<m;i++) 
		cin >> E[i].bef >> E[i].aft >> E[i].wei;// 집어넣고
	sort(E,E+m,cmp);//집어넣은거 weight 순으로 정렬
	DP(m);
	for (int i=0;i<m;i++)
		Cmp(output, save[i]);//save[]에 저장된 값들중 가장큰것을 뽑는다.
	cout << output;
	cin>>n;
}