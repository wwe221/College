#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int size;
	cout << "�� ���� ������ �Է�? ";
	cin >> size;
	int* arr = new int [size];
	cout << "������ �Է��Ͻÿ�.\n";
	for (int i = 0; i < size; i++)
	cin >> arr[i];
	double sum = 0;
	for (int i =0;i<size; i++)
		sum +=sqrt((double)*(arr+i));
	cout << sum << endl;
	delete[] arr;
	return 0;
}
	