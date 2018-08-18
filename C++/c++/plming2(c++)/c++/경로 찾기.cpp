#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str ="d:\\My Libraray\\Temp\\test.jpg";
	int last= str.find_last_of ("\\");
	string s =str.subst(str.length-last,last);
	cout<<s;
	return 0;
}