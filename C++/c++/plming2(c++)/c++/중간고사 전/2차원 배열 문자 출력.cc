#include<iostream>
using namespace std;
int main()
{
	char* pex[]={"scientia","est","potentia"};
	int a  ;
	int b  ;
	int i = 0 ;
	while(i<=2){
		a = 0;
		b = 0;
		
		while(true)
	{
			b++;
			if (*(pex[i]+a)=='\0')
				break;
				a++;
	}
		while(a>=0){
			cout<<*(pex[i]+a);
			a--;
	}
		cout<<"\n";
		i++;
	}	
	return 0;
}
	