#include "tree.h"

void main()
{
	int i;
	char n[10];
	char a[10],b[10];
	node tree;
	tree.build(-1);
	node lnode;
	ifstream fcin("조선왕조.txt");
	fcin>>n;
	tree.croot(n);
	while(!fcin.eof()){
		fcin >> b >> a;
		cout << a << "," << b << endl;
		lnode.cbuild(b);
		tree.make_ct(a,lnode);
	}
	fcin.close();
	//tree.inorder();
	cout<<"--------왕과 자식들 출력 실행\n";
	tree.print();
	cout<<"--------왕만 출력 실행\n";
	tree.printt();
	cout<<"--------역순 출력 실행\n";
	tree.revprint();
	cout<<"--------조선의 왕의 수 출력\n";
	tree.countking();
	cout<<"총";
	tree.get_cnt();
	cout<<"명 입니다\n";
	cout<<"--------인조의 후손 출력\n";
	tree.injo();
	cout<<"--------직계후손이 왕이되지 못한 왕 출력\n";
	tree.sonnotking();
	cout<<"--------직계후손이 왕이된 수가 가장 많은왕 출력\n";
	tree.mostsonking();
	cout<<"--------정종의 왕이된 형제 출력\n";
	tree.jjbro();
	cout<<"--------순종의 선조들 출력\n";
	tree.soonfathers();
	cout<<"--------직계 후손이 2명이상 왕이된 왕 출력\n";
	tree.twosonking();
	cout<<"총";
	tree.get_cnt();
	cout<<"명 입니다\n";
	cout<<"--------예종은 태종의 몇대후손인지 출력\n";
	tree.howdae();
	tree.get_cnt();
	cout<<"대손 입니다\n";
	
	
	
	
	cin>>i;


}
