#include "tree.h"

void main()
{
	int i;
	char n[10];
	char a[10],b[10];
	node tree;
	tree.build(-1);
	node lnode;
	ifstream fcin("��������.txt");
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
	cout<<"--------�հ� �ڽĵ� ��� ����\n";
	tree.print();
	cout<<"--------�ո� ��� ����\n";
	tree.printt();
	cout<<"--------���� ��� ����\n";
	tree.revprint();
	cout<<"--------������ ���� �� ���\n";
	tree.countking();
	cout<<"��";
	tree.get_cnt();
	cout<<"�� �Դϴ�\n";
	cout<<"--------������ �ļ� ���\n";
	tree.injo();
	cout<<"--------�����ļ��� ���̵��� ���� �� ���\n";
	tree.sonnotking();
	cout<<"--------�����ļ��� ���̵� ���� ���� ������ ���\n";
	tree.mostsonking();
	cout<<"--------������ ���̵� ���� ���\n";
	tree.jjbro();
	cout<<"--------������ ������ ���\n";
	tree.soonfathers();
	cout<<"--------���� �ļ��� 2���̻� ���̵� �� ���\n";
	tree.twosonking();
	cout<<"��";
	tree.get_cnt();
	cout<<"�� �Դϴ�\n";
	cout<<"--------������ ������ ����ļ����� ���\n";
	tree.howdae();
	tree.get_cnt();
	cout<<"��� �Դϴ�\n";
	
	
	
	
	cin>>i;


}
