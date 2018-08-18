#include "bst.h"

void node::insert ( int key )
{
//	degenerate case: root node에 삽입
	if ( this->item == -1 ) {
		this->item = key;
		return;
	}

//	if key > this->item -> 오른쪽 차일드로
	if ( key > this->item ) {
	//	만약 오른쪽 차일드가 널이 아니면
		if ( this->rchild != NULL ) {
			this->rchild->insert ( key );
		}
	//	만약 오른쪽 차일드가 널이라면
		else {
			node *temp = (node *) malloc ( sizeof(node) );
			temp->build ( key );
			this->rchild = temp;
		}
	}
//	if key < this->item -> 왼쪽 차일드로
	else if ( key < this->item ) {
	//	만약 왼쪽 차일드가 널이 아니면
		if ( this->lchild != NULL ) {
			this->lchild->insert ( key );
		}
	//	만약 왼쪽 차일드가 널이라면
		else {
			node *temp = (node *) malloc ( sizeof(node) );
			temp->build ( key );
			this->lchild = temp;
		}
	}
//	key == this->item
	else {
		printf("Error\n");
		return;
	}
}

void node::search ( int key )
{
//	if key == this->item
	if ( key == this->item ) {
		printf("Found %d\n", key);
		return;
	}
//	if key > this->item -> 오른쪽 차일드로
	else if ( key > this->item ) {
	//	만약 오른쪽 차일드가 널이 아니면
		if ( this->rchild != NULL )
			this->rchild->search ( key );
	//	만약 오른쪽 차일드가 널이라면
		else
			printf("Cannot find %d\n", key);
	}
	else {
//	if key < this->item -> 왼쪽 차일드로
	//	만약 왼쪽 차일드가 널이 아니면
		if ( this->lchild != NULL )
			this->lchild->search ( key );
	//	만약 왼쪽 차일드가 널이라면
		else
			printf("Cannot find %d\n", key);
	}
}

void node::inorder ( )
{
	if ( this->lchild != NULL )
		this->lchild->inorder ( );

	cout<<this->item<<"\n";

	if ( this->rchild != NULL )
		this->rchild->inorder ( );
	if ( this->mchild != NULL)
		this->mchild ->inorder();
}