#include"stack.h"


void main(){
	ifstream fcin("C:/StdList.txt");
	int i;
	int nStds=0;
	int a;
	double e;
	char b[8],c[8],d[8];
	StdStack sStd;
	StdInfo tStd;
	int tid;
	char tname[10];
	char tdept[10];
	char tcity[10];
	double tgpa;	
	while(!fcin.eof()){
		fcin>>a>>b>>c>>d>>e;
		++nStds;}	
	fcin.close();
	sStd.create(nStds);
	ifstream fin("C://StdList.txt");
	for(int i=0;i<nStds;i++){
		fin >> tid >> tname>> tdept>> tcity>> tgpa;	
		tStd.build (tid, tname, tdept, tcity ,tgpa);
		sStd.Push(tStd);}
	sStd.Pop();
	tStd.print();
	cin>>i;
	fcin.close();







}