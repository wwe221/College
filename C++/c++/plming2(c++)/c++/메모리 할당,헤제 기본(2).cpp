#include<iostream>
#include<cmath>
using namespace std;

void sum(int a, int b, int c, double&sum1, double&sum2){
	int arr[]={a,b,c};
	for (int i =0;i<3; i++)
		sum1 += sqrt((double)*(arr+i));
	for (int i =0;i<3; i++)
		sum2 += pow((double)*(arr+i),2);
cout<<sum1<<'\t'<<sum2<<endl;}

int main(){
	int size;
	cout << "�� ���� ������ �Է�? ";
	cin >> size;
	int* arr = new int [size];
	cout << "������ �Է��Ͻÿ�.\n";
	for (int i = 0; i < size; i++)
	cin >> arr[i];
	double sum1=0,sum2=0;
	sum(arr[0],arr[1],arr[2],sum1,sum2);
	cout << sum1<<endl<<sum2<< endl;
	delete[] arr;
	return 0;
}
	