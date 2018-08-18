#include "tree.h"

void node::build ( int _item )
{
	item = _item;
	lchild = rchild = NULL;
}

int node::is_empty ( )
{
	if ( item == -1 )
		return 1;
	else
		return 0;
}

void node::insert( int key )
{	

// if key > this->item à 오른쪽 차일드로
// 만약 오른쪽 차일드가 널이 아니면
// 만약 오른쪽 차일드가 널이라면
// if key < this->item à 왼쪽 차일드로
// 만약 왼쪽 차일드가 널이 아니면
// 만약 왼쪽 차일드가 널이라면

// degenerate case: root node에 삽입
	if(this->item==-1){
		this->build(key);
		i++;		
		return;}
	else
		if (this->item==NULL)
			this->build(key);
		else if(key>this->item)
			if(this->rchild==NULL){
				node *temp = new node(key);
				temp->build(key);
				this->rchild = temp;}
			else
				this->rchild->insert(key);

		else if(key<this->item){
			if(this->lchild==NULL){
				node *temp = new node(key);
				temp->build(key);
				this->lchild = temp;}
			else
				this->lchild->insert(key);}
	
		else 
			cout<<"이미 있는 값임 이사람아\n";
	

}

void node::search ( int key )
{
	if(this->item==key)
		cout<<"여기있었네\n";
	else if (key>this->item){
		if(this->rchild==NULL)
			cout<<"없음\n";
		else
			this->rchild->search(key);}
	else
		if(this->lchild==NULL)
			cout<<"없음\n";
		else
			this->lchild->search(key);

}

void node::inorder()
{
	if ( this!=NULL ){
		lchild->inorder();
		cout << "[" << item << "] \n";
		rchild->inorder();
	}
}


//void node::print()
//{	
//	for(;this=
//	if(this->lchild!=NULL){
//		this->lchild->print();}
//	else
//		cout<<this->item<<"\n";
//}
