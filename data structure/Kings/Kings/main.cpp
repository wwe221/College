#include "tree.h"
void main ( )
{
	/*int i;	
	int n;
	int a, b, c;
	node tree;
	node lnode, rnode;
	ifstream fcin("tree.txt");
	fcin >> n;
	for ( i = 0; i < n; i++ )
	{
		fcin >> a;
		cout << a << endl;
		tree.insert ( a );
		}
	fcin.close();
	tree.search ( 10 );
	tree.search ( 15 );
	tree.inorder ( );
	*/
	node tree(-1);
	tree.insert(10);
	tree.insert(8);
	tree.insert(12);
	tree.insert(21);
	tree.insert(6);
	tree.insert(1);
	tree.insert(5);
	tree.insert(15);
	tree.insert(15);
	tree.search(10);
	tree.search(14);
	tree.inorder();
	int i;
	cin>>i;
}