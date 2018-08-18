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

	for(int i=0;i<nStds-1;i++){
	fin >> tid >> tname>> tdept>> tcity>> tgpa;
	cout << tid<<"	"<< tname << "	"<<tdept << "	"<<tcity<< "	"<<tgpa<<endl;
	tStd.build (tid, tname, tdept, tcity ,tgpa);
	cStdList.insertname(tStd);
	}
	cout<<"\n\n\n\n";
	cStdList.search("±è»óÀ±");
	fin.close();
	cStdList.print();
	cin>>i;
}
	


