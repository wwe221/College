#include "bst.h"

void node::insert ( int key )
{
//	degenerate case: root node�� ����
	if ( this->item == -1 ) {
		this->item = key;
		return;
	}

//	if key > this->item -> ������ ���ϵ��
	if ( key > this->item ) {
	//	���� ������ ���ϵ尡 ���� �ƴϸ�
		if ( this->rchild != NULL ) {
			this->rchild->insert ( key );
		}
	//	���� ������ ���ϵ尡 ���̶��
		else {
			node *temp = (node *) malloc ( sizeof(node) );
			temp->build ( key );
			this->rchild = temp;
		}
	}
//	if key < this->item -> ���� ���ϵ��
	else if ( key < this->item ) {
	//	���� ���� ���ϵ尡 ���� �ƴϸ�
		if ( this->lchild != NULL ) {
			this->lchild->insert ( key );
		}
	//	���� ���� ���ϵ尡 ���̶��
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
//	if key > this->item -> ������ ���ϵ��
	else if ( key > this->item ) {
	//	���� ������ ���ϵ尡 ���� �ƴϸ�
		if ( this->rchild != NULL )
			this->rchild->search ( key );
	//	���� ������ ���ϵ尡 ���̶��
		else
			printf("Cannot find %d\n", key);
	}
	else {
//	if key < this->item -> ���� ���ϵ��
	//	���� ���� ���ϵ尡 ���� �ƴϸ�
		if ( this->lchild != NULL )
			this->lchild->search ( key );
	//	���� ���� ���ϵ尡 ���̶��
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