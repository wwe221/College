#include "bst.h"

void main ( ) 
{
	node tree;

	tree.insert ( 10 );
	tree.insert ( 8 );
	tree.insert ( 12 );
	tree.insert ( 21 );
	tree.insert ( 6 );
	tree.insert ( 1 );
	tree.insert ( 5 );
	tree.insert ( 15 );

	tree.search ( 10 );

	tree.search ( 14 );

	tree.inorder ( );
	int i;
	cin  >>i;
}
