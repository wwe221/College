#include <iostream>
#include <stdio.h>
using namespace std;
/*ȸ������� ������ ��� greedy �˰����� �̿��ϱ� ���� �������� ��ġ���� �̹� ȸ���� ���ڵ��� �����ѵ� ���� �����͵��� ȸ���� �ƴѰ͵��� ���� �ٲٴ� �������� �����ߴ�.
�̹� ȸ���� ���ڵ��� �����ϱ����� check ������ p������ Ȱ���ߴ�.
char ���� ������ �ϰ� �Ǹ� ASCII�ڵ�� ������ �̷�����µ� ���Ĺ������ ASCII�ڵ忡 ����� �ֱ� ������ �� ���ڿ� - �����ѰͿ� ������ ���ϰ� �Ǹ� �ѹ��ڿ��� ������ ���ڷ� �ٲٱ� ���� ����� ������ �ȴ�.*/

int n , m;//�� ���� ����,������
char input[500];//��ǲ�� �����ϴ� �迭
int output = 0;//�ƿ�ǲ
int check =0;//Greedy �ϰ� Ǯ����� ���� ����.
int p;//ȸ���� ���ϱ� ���� ������ ����� ���� ����.

int minimum(int a,int b){//���� �������� �����ϴ� �Լ�
	if(a>b)
		return b;
	else
		return a;
}
int positive(int a){//��ǲ�� ������ ����� �ٲٴ� �Լ�
	if(a<0)
		a=-a;
	return a;
}
void Greedy(){ //check���� ���� p���� 
	int sub=0;
	for(int i = check; i <= p; i++ ) //���ڸ� �ٲٰ�, ����� ����Ѵ�.
  {
    sub= positive(input[i] - input[n-1-i]);//�� ������ ���� ���밪���� ȯ���Ѵ�.
    output += minimum(sub,26 - sub);//������ ����� ���� ���ĺ������� �ڷ� �� ���� �ּҰ��� ���Ѵ��� output�� ���Ѵ�.
  }
  if(check < p)/*���� check�� p ���� ������ ���� ���ʿ� ��ġ�Ѱ��̶�� ���� �������� check�� ���̿� p�� ������ �ּҰ��� ���ϰ� ���� ���� �� �����ش�. �ƴ϶�� ���� �ּҸ� �����ش�.
�̴� Ŀ���� ������ �����̴� ���� �� >or<�� ������ �Ͼ�� ����� ����ϱ� �����̴�.*/
    output += minimum(positive(m - check), positive(m - p)) + (p- check);
  else if (check == p)
	  output += positive(m - p);
  else
	  output += minimum(positive(m - check), positive(m - p));
}
void main(){	

	cin>>n>>m; //�Է�
	m--;
	for(int i=0;i<n;i++){
		cin>>input[i];} //�Է�	
	p = n/2 - 1;

	if(n/2 <= m)//�������� ������ ���ų� ũ��
		m = n - m-1;//�������� �ű��.
  
	while(check < n/2 && input[check] == input[n-1-check])	//ó�� ���ڰ� ȸ������ üũ�� �ϰ�,������ �������� �Ѿ��.���� greedy �ϰ� ������ ��� ���� ���ȴ�.
		check++;
	while(p >=0 && input[p] == input[n-1-p] )	//ȸ������ üũ�� �ϱ����� ������ �߽����� ã�´�.
		p--;
	//
	
	Greedy();
	cout<<output<<endl;
	cin>>n;	
}