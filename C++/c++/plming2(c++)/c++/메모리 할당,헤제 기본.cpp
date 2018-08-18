#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int size;
	cout << "몇 개의 정수를 입력? ";
	cin >> size;
	int* arr = new int [size];
	cout << "정수를 입력하시오.\n";
	for (int i = 0; i < size; i++)
	cin >> arr[i];
	double sum = 0;
	for (int i =0;i<size; i++)
		sum +=sqrt((double)*(arr+i));
	cout << sum << endl;
	delete[] arr;
	return 0;
}
	