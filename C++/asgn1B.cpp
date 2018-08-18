#include <iostream>
using namespace std;
int main()
{
	int b;
	int n;
	int i;
	float bn;
	cout<<"두 양의 정수를 입력하시오\n";
	cin >> b >> n ;
	
	bn=1;
	i=1;
	while(i<=n){
		bn=bn*b;
		i++;	
	}	
	if (bn>=4294967295 || n<0 || 4294967295<n || b<0 || 4294967295<b){
			cout<<"잘못된 입력입니다.\n";
	}
	
	else {cout<<"power("<<b<<","<<n<<") ="<<bn;
	
	}
 return 0;
}
		