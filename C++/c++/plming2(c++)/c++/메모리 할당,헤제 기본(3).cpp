#include<iostream>
using namespace std;

int avearray(float a[],int b){
	float sum=0 ,aver;
	for(int i=0;i<b;i++)
		sum+=a[i];
	aver=sum/5;
	return aver;
}
int main(){
	int size;
	float sum = 0;
	float aver;
	cout << "�� ���� ������ �Է�? ";
	cin >> size;
	float* arr = new float [size];
	cout << "������ �Է��Ͻÿ�.\n";
	for (int i = 0; i < size; i++)
	cin >> arr[i];
	for(int i=0;i<size;i++)
		if(arr[i]>aver)
			cout << aver << arr[i]<<"\t";
	delete [] arr;
	return 0;
}