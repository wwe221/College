#include<iostream>
#include<stdio.h>
using namespace std;
/*
Red-Green Tower problem�� �ذ��ϱ� ����
DD �Լ��� �̿��� 
�ɼ��ִ� ��� ����� ���� ���� ������ �ִ� ���� co �迭�� �����ѵ�,
count()�Լ��� ù��° for������ co�迭�� ����Ǿ��ִ� ����ū ������ height�� �����Ѵ�.
count()�Լ��� �ι�° for������ co�迭�� ���ҵ��� height�� �������� cnt�� �����ѵ� ����ϴ� ��������
������� �������ִ� ž�� ����Ǽ��� ���ߴ�.
*/

int r, g;//red �� green Block 
int co[99999];//����Ǽ��� ���� ���� ���� �����ϴ� �迭, ����Ǽ��� 100,000 �� �Ѿ�� �����Եȴ�.
int cc = 0;//�迭�� index.�����Ҷ����� 1����

void DD(int rr, int gg, int ffl){
	/*���� red �� green Block�� ���� ���� ������ ffl�� ����
	������ �ٸ� �۾��� �����ϵ��� �Ͽ���.*/	
	co[cc] = ffl;
	cc++;
	if (ffl > rr&&ffl > gg){
		return;
	}
	if (ffl > rr&&gg > ffl)
		DD(rr, gg - ffl, ffl + 1);
	else if (ffl > gg&&rr > ffl)
		DD(rr - ffl, gg, ffl + 1);
	else if (ffl == gg || ffl == rr){
		if (ffl == gg)
		DD(rr, gg - ffl, ffl + 1);
		else if (ffl==rr)
		DD(rr - ffl, gg, ffl + 1);
	}
	if (rr > ffl && gg > ffl){
		DD(rr - ffl, gg, ffl + 1);
		DD(rr, gg - ffl, ffl + 1);
	}
}
void count(){
	int height = 0;
	for (int i = 1; i < cc; i++){//���� �������� ���ϴ� for��
		if (co[i]>height)
			height = co[i];
	}
	int cnt = 0;
	for (int i = 0; i < cc; i++){//����������� ����Ǽ��� ���� for��
		if (co[i] == height)
			cnt++;
	}
	if (cnt == 0)
		return;
	cout << cnt;
}
void main(){
	cin >> r >> g;
	if (r == 1&&g == 1)//r��g�� ��� 1�϶�
		cout << 2;
	else if (r == 0 && g != 0 || r != 0 && g == 0)//r �� g �����ϳ��� 0�϶�
		cout << 1;
	else
		DD(r, g, 1);
	count();
	/*for (int i = 0; i<cc; i++)
		cout << co[i] << "\t";*/


	cin >> cc;

}