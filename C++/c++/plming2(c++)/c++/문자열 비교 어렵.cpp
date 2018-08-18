#include<iostream>
#include<string>
using namespace std;


int main(){
	string s="Napster's pay-to-play service is officially out.";
	string targetS ="er";
	int len=0,len1=0;
	while(true){
	len = s.find(targetS);
	if(len<0)
		break;
	else{len1++;}
	s=s.substr(len+1,s.length());}
	cout<<len<<"\t"<<len1;
return 0;
}