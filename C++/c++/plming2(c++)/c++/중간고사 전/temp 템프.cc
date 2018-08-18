
#include <iostream>
#include <bitset>
using namespace std;
int main()
{
	unsigned short int temp;
	unsigned short int zero = 0x0000;
	unsigned short int one = 0x0001;
	int count = 0;
	cout<<"정수 입력";
	cin >> temp;
	cout<<"temp=" << bitset<16>(temp)<<"\n";
	while(true)
	{
		if(temp & one)
			count=count +1;
		temp = temp>>1;
		if(temp ==zero)
			break;
	}
    cout<<"1의 갯수:"<< count;
    return 0;
}