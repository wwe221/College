#include "list.h"


void main(){
	ifstream fcin("C://StdList.txt");
	int i;
	int nStds=0;
	int a;
	double e;
	char b[8],c[8],d[8];
	StdList cStdList;
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
	ifstream fin("C://StdList.txt");

	cStdList.create(nStds);
	cout<<"어떤 종류의 삽입을 할것입니까?\n --- 1. 순서를 고려하지 않은 삽입 ---\n --- 2. 순서를 고려한 삽입(이름순) ---\n --- 3.순서를 고려한 삽입(성적순) ---";
	char select;
	cin >>select;
	switch(select){
	case'1':
		for(int i=0;i<nStds-1;i++){
			fin >> tid >> tname>> tdept>> tcity>> tgpa;
			cout	 << tid<<"	"<< tname << "	"<<tdept << "	"<<tcity<< "	"<<tgpa<<endl;
			tStd.build (tid, tname, tdept, tcity ,tgpa);
			cStdList.insert(tStd);}
			cout<<"\n\n\n\n";
			break;
	case'2':
		for(int i=0;i<nStds-1;i++){
			fin >> tid >> tname>> tdept>> tcity>> tgpa;
			cout	 << tid<<"	"<< tname << "	"<<tdept << "	"<<tcity<< "	"<<tgpa<<endl;
			tStd.build (tid, tname, tdept, tcity ,tgpa);
			cStdList.insert_name(tStd);}
			cout<<"\n\n\n\n";
			break;
	case'3':
		for(int i=0;i<nStds-1;i++){
			fin >> tid >> tname>> tdept>> tcity>> tgpa;
			cout	 << tid<<"	"<< tname << "	"<<tdept << "	"<<tcity<< "	"<<tgpa<<endl;
			tStd.build (tid, tname, tdept, tcity ,tgpa);
			cStdList.insert_gpa(tStd);}
			cout<<"\n\n\n\n";
			break;
	default:
		cout<<"잘못된 입력입니다.";
		break;}

	fin.close();
	cStdList.print();
	//cStdList.remove("백승호");
	cStdList.bisearch("이상윤");	
	cStdList.search("현수아");
	cStdList.print();
	cStdList.bestGpa();
	cStdList.worstGpa();
	cStdList.averGpa();
	cStdList.over4();
	cStdList.kim();
	cStdList.ilsan();
	cin>>i;}	