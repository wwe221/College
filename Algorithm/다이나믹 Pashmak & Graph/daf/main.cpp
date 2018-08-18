#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
/* �� �������� weight�� ������ ���·� �迭�� �ְ�, weight�� ������ �Ѵ� �迭�� �ִ´�.
���� �ϰ� �Ǹ� �� ������ weight ���� ���� �����ǰ� �ϴ����� �̿���, �̾����� ��ΰ� ���� �� ���̸� ����Ѵ�.

*/
int save[5000], from[5000], to[5000];//from�� ������ ����V , to�� ������ ����V.
int n, m;//�Է¹޴°� n,m
int output;//���������� ���� output
int cnt;//�迭�� �����Ҷ��� ���̸� �����Ҷ� ������ �������� ����
struct Edge
{
	int from, to, wei;//���� ����,���� ����,weight�� ��Ÿ����
}E[5000];
bool cmp(struct Edge a, struct Edge b) //����ü�� ���ҵ��� �����ϴ� �Լ� (���� http://blog.secmem.org/297)
{
	return a.wei<b.wei;
}
int Change(int a, int b)//a�� b�� ���ؼ� �� ū ���� �����Ѵ�.
{
	if (a>b)
		return a;
	else 
		return b;
}
void Save(){//���̸� ���ؼ� �����Ѵ�.
	if (cnt < 0)
		return;
	else{
		cnt--;
		save[to[cnt]] = Change(save[to[cnt]], from[cnt]);
	}
}
void DP(int cntt){
	if (cntt < m){//�ִ� m��(������ ��)��ŭ �����Ѵ�.
		from[0] = save[E[cntt].from] + 1;// �ʱ�ȭ
		cnt = 1;//�ʱ�ȭ
		to[0] = E[cntt].to;//���
		while (E[cntt].wei == E[cntt + 1].wei){//���� weight�� ������ ������ ������ �ʵ��� ����ó��
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
		cin >> E[i].from >> E[i].to >> E[i].wei;// ����ְ�
	sort(E, E + m, cmp);//��������� weight ������ ����
	DP(0);
	for (int i = 0; i<m; i++)
		output=Change(output, save[i]);//save[]�� ����� ������ ����ū���� �̴´�.
	cout <<	output;
	cin >> n;
}