
#include <iostream>
using namespace std;
int main()
{
	unsigned short int a;
	unsigned short int zero = 0x0000000000000000;
	unsigned short int one = 32768;
	int i = 0;
	cout<<"정수를 입력";
	cin >> a;
	
	while(i<16)
   {
      if(a & one){
         cout<<1;
         a = a<<1;
         i++;}
      
      else{
         cout<<0;
         a = a<<1;
         i++   ;}
	}
	
    return 0;
}