#include "link.h"

void main(){
	ifstream fcin("StdList.txt");
	int i;
	int nStds=0;
	int a;
	double e;
	char b[8],c[8],d[8];	
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
	nptr StdFirst = new node();
	StdFirst->create(nStds);
	ifstream fin("StdList.txt");
	for(int i=0;i<nStds-1;i++){
		fin >> tid >> tname>> tdept>> tcity>> tgpa;		
		//cout	 << tid<<"	"<< tname << "	"<<tdept << "	"<<tcity<< "	"<<tgpa<<endl;
		tStd.build (tid, tname, tdept, tcity ,tgpa);		
		StdFirst->insert(tStd);
	}
	cout<<"\n\n\n\n";
	
	StdFirst->print ( );
	StdFirst->search ( "¹é½ÂÈ£" );
	StdFirst->search ( "ÀÌ»óÀ±" );
	StdFirst->remove ( "¹é½ÂÈ£" );
	StdFirst->remove ( "¹é½ÂÈ£" );
	StdFirst->print ( );
	StdFirst->queqtion_five ( ); 
	StdFirst->queqtion_six ( ); 
	StdFirst->queqtion_seven ("ÀÏ»ê"); 
	/*StdFirst->queqtion_eight ( ); 
	StdFirst->queqtion_nine ( );*/
	cin>>i;
	}