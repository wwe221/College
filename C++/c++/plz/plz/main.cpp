#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/* ��Ȱ�� ����� ���� ���������Լ����� m���� e-1�� �����Ͽ����ϴ�.
10������ ��ȯ�� ���� ����int �� �������ִ�
8�ڸ� �̻�(16������ ��� 5F5E100) �� �Ǹ� ��Ȯ�� ����� �����ʴ� �Լ��Դϴ�.*/

int final(int a, int b);//���ϰ� ��� �Լ�
int cnt(char a);//���ڸ��� ���� �Լ�
int Dnc(char a[],int s,int e);//�������� �Լ�

int numb = 0; //������or ���� �
int hm = 0;	  //���ڸ���
int sum = 0; // ��� ��ȣ	
char *ele;//���ҹ迭

void main(){	
	char **pwd;	// �м��� ��ȣ���� ���� �迭 ����
	ifstream fcin("password.txt");
	fcin >> numb;
	fcin >> hm;
	ele = new char [numb];
	 // ��ȣ���ҵ��� ���� �迭 ����
	for (int i = 0; i < numb; i++){
		fcin >> ele[i]; // ���ҵ��� �迭�� ����
	}
	fcin >> sum;
	pwd = new char*[sum];//�� sum���� ��ȣ���� ���� �迭 ����
	for (int i = 0; i < sum; i++)
		pwd[i] = new char[hm];
	for (int i = 0; i < sum; i++)//�迭�� ��ȣ ����
		for (int j = 0; j < hm; j++)
			fcin >> pwd[i][j];
	for (int i = 0; i < sum; i++){//��ȣ Ȯ��
		cout<<i+1<<"��° ��ȣ:	";
		for (int j = 0; j < hm; j++)
			cout << pwd[i][j];
		cout <<"\n";
	}
	for(int i=1;i<=sum;i++)//���� ���
		cout<<i<<"�� ��ȣ��  "<<Dnc(pwd[i-1],0,hm-1)+1<<"��° �Դϴ�\n";
	
	cin >> hm;
}
int Dnc(char a[],int s,int e){/*�������� �Լ�(hm�ڸ��� ��ȣ�� �ϳ��� ���������� 
							  ������ ����, ������ʰ���numb{����}�� ���Ѵ��� �����ʰ���
							  ���ϴ� �������� �ϴ� �Լ��Դϴ�).*/
	int m,L,R;
	if( s==e)
		return cnt(a[s]); //���� �ϳ��� ������� �װ��� ����Ͽ��� �����մϴ�.
	m = e-1;
	L = Dnc(a,s,m);
	R = Dnc(a,m+1,e);
	return final(L,R);
}
int final(int a, int b){//���ϰ� ��� �Լ�
	return (a*numb+b);
}
int cnt(char a){//��ȣ �ϳ��� �� ���(��ȣ�� �ڸ����� 10������ ����Ѱ� ����)
	int rtn=0;
	for(int i=0;i<numb;i++)
		if(a==ele[i]){
			rtn=i;
			break;}
	return rtn;
}