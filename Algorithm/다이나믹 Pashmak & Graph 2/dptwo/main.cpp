#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int save[5000],from[5000],to[5000];//from�� ������ ����V , to�� ������ ����V.
int n,m;//�Է¹޴°� n,m
int output;//���������� ���� output

struct Edge
{
	int bef,aft,wei;	
}E[5000];
bool cmp(struct Edge a, struct Edge b)
{
	return a.wei<b.wei;
}
void Cmp(int &a,int b)//a�� b�� ���ؼ� ��ū�� a�� �ִ´�.
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
		to[0] = E[i].aft;//õ��°�� ������ �޴� vertex
		for (; E[i].wei == E[i + 1].wei; i++){
			from[cnt] = save[E[i + 1].bef] + 1;//�������� ���ֱ�			
			to[cnt++] = E[i + 1].aft;//�������� ���ֱ�
		}
		while (cnt>=0){//���ʿ��� ����
			cnt--;//cnt 0����
			Cmp(save[to[cnt]],from[cnt]);//save[����V]�� ����V[]�� ���ؼ� save�� �����Ѵ�.
		}
	}
}
int main()
{	
	cin >> n >> m;
	for (int i=0;i<m;i++) 
		cin >> E[i].bef >> E[i].aft >> E[i].wei;// ����ְ�
	sort(E,E+m,cmp);//��������� weight ������ ����
	DP(m);
	for (int i=0;i<m;i++)
		Cmp(output, save[i]);//save[]�� ����� ������ ����ū���� �̴´�.
	cout << output;
	cin>>n;
}