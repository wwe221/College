#include<iostream>
using namespace std;
//it's so fucking complicated
struct stds
{	int sNum;
int score;};

void my_sum_aver(stds&a,stds&b,stds&c,int& sum,double& aver){
	sum = a.score+b.score+c.score;
	aver = sum/3;
	
}
	int main()
{	
	stds std1= {1,90};
	stds std2 = {2,80};
	stds std3 = {3,70};
	int sum = 0;
	double aver;
	my_sum_aver(std1,std2,std3,sum,aver);
	cout<<aver<<'\n'<<sum;
	return 0;}