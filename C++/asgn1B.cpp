#include <iostream>
using namespace std;
int main()
{
	int b;
	int n;
	int i;
	float bn;
	cout<<"�� ���� ������ �Է��Ͻÿ�\n";
	cin >> b >> n ;
	
	bn=1;
	i=1;
	while(i<=n){
		bn=bn*b;
		i++;	
	}	
	if (bn>=4294967295 || n<0 || 4294967295<n || b<0 || 4294967295<b){
			cout<<"�߸��� �Է��Դϴ�.\n";
	}
	
	else {cout<<"power("<<b<<","<<n<<") ="<<bn;
	
	}
 return 0;
}
		