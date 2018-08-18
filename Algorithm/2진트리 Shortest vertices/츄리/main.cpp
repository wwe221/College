#include "tree.h"

void main()
{
	int i;
	int n,m;
	int ai, bi, a, b, ti, vi;	
	node tree;
	tree.build(-1);
	node lnode , rnode;
	ifstream fcin("text.txt");
	fcin >> n>> m;
	fcin>>ai>>bi;
	tree.root(ai);
	lnode.build(bi);
	tree.make_t(ai, lnode);
	//cout << ai << "," << bi << endl;
	for(int i=0;i<(n-2);i++){
		fcin >> b >> a;
		//cout << b << "," << a << endl;
		lnode.build(a);
		tree.make_t(b, lnode);
	}
	for (i = 0; i < m; i++){
		fcin >> ti >> vi;
		tree.Order(ti, vi);
	}	
	fcin.close();
	cin>>i;	
}
