#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
/* 각 엣지들을 weight로 정렬한 상태로 배열에 넣고, weight가 같으면 둘다 배열에 넣는다.
정렬 하게 되면 각 엣지의 weight 들이 점점 증가되게 하는점을 이용해, 이어지는 경로가 가장 긴 길이를 계산한다.

*/
int save[5000], from[5000], to[5000];//from은 엣지의 시작V , to는 엣지의 도착V.
int n, m;//입력받는값 n,m
int output;//최종적으로 계산될 output
int cnt;//배열에 삽입할때와 길이를 저장할때 순서를 세기위한 변수
struct Edge
{
	int from, to, wei;//각각 시작,도착 엣지,weight를 나타낸다
}E[5000];
bool cmp(struct Edge a, struct Edge b) //구조체의 원소들을 정렬하는 함수 (참고 http://blog.secmem.org/297)
{
	return a.wei<b.wei;
}
int Change(int a, int b)//a와 b를 비교해서 더 큰 것을 리턴한다.
{
	if (a>b)
		return a;
	else 
		return b;
}
void Save(){//길이를 비교해서 저장한다.
	if (cnt < 0)
		return;
	else{
		cnt--;
		save[to[cnt]] = Change(save[to[cnt]], from[cnt]);
	}
}
void DP(int cntt){
	if (cntt < m){//최대 m번(엣지의 수)만큼 수행한다.
		from[0] = save[E[cntt].from] + 1;// 초기화
		cnt = 1;//초기화
		to[0] = E[cntt].to;//기록
		while (E[cntt].wei == E[cntt + 1].wei){//같은 weight가 있을때 연산이 꼬이지 않도록 예외처리
			from[cnt] = save[E[cntt + 1].from] + 1;		
			to[cnt++] = E[cntt + 1].to;
			cntt++;		
		}
		Save();
		cntt++;		
	}
	else
		return;
	DP(cntt);
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i<m; i++)
		cin >> E[i].from >> E[i].to >> E[i].wei;// 집어넣고
	sort(E, E + m, cmp);//집어넣은거 weight 순으로 정렬
	DP(0);
	for (int i = 0; i<m; i++)
		output=Change(output, save[i]);//save[]에 저장된 값들중 가장큰것을 뽑는다.
	cout <<	output;
	cin >> n;
}