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
	cout<<"� ������ ������ �Ұ��Դϱ�?\n --- 1. ������ ������� ���� ���� ---\n --- 2. ������ ����� ����(�̸���) ---\n --- 3.������ ����� ����(������) ---";
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
		cout<<"�߸��� �Է��Դϴ�.";
		break;}

	fin.close();
	cStdList.print();
	//cStdList.remove("���ȣ");
	cStdList.bisearch("�̻���");	
	cStdList.search("������");
	cStdList.print();
	cStdList.bestGpa();
	cStdList.worstGpa();
	cStdList.averGpa();
	cStdList.over4();
	cStdList.kim();
	cStdList.ilsan();
	cin>>i;}	