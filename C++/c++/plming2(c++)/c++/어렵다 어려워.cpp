#include<iostream>
using namespace std;

void SLS(char ch[],char c[],int c1){
	int i;
	for(i=0;i<c1-2;++i)
		c[i]=ch[i+1];
		
	c[c1-1]=ch[0];
	c[c1]='\0';
}
int main(){
	char mess[]="BINGO JJANG!!!";
	char* copy= new char[15];
	char * copy1= new char[15];
	SLS(mess,copy,14);
	SLS(copy,copy1,14);
	cout << mess <<endl<<copy<<endl<<copy1<<endl;
	delete [] copy;
	delete [] copy1;
	return 0;
}