#include <iostream>
using namespace std;
int main()
{
	int b;
	int n;
	int i;
	float bn;
	cout<<"첫번째 자연수를 입력하시오";
	cin >> b;
	cout<<"두번째 자연수를 입력하시오";
	cin >> n;
	
	bn=1;
	i=1;
	if (n<0)
	{
		while(i<=-n){
			bn=bn/b;
			i++;
		}
	}
	while(i<=n){
		bn=bn*b;
		i++;
		
		
	}
	cout<<"power("<<b<<","<<n<<") ="<<bn;
 return 0;
}
		