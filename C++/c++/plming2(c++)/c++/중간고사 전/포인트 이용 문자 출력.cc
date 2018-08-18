#include<iostream>
using namespace std;
int main()
{
	char* pex="scientia est potentia";
	int i = 0 ;
	int n = 0 ;
	while(true)
	{
		n++;
		if (*(pex+i)=='\0')
			break;
		i++;
	}
	while(i>=0){
		cout<<*(pex+i);
		i--;
	}
	return 0;
}
	