#include <iostream>
using namespace std;
int main()
{
	int b;
	int n;
	int i;
	float bn;
	cout<<"ù��° �ڿ����� �Է��Ͻÿ�";
	cin >> b;
	cout<<"�ι�° �ڿ����� �Է��Ͻÿ�";
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
		