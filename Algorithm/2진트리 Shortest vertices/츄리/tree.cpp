#include "tree.h"

void node::root(int _item)
{
	if ( this->item==-1) {
		this->item = _item;
		strcpy(this->color, "Red");
		this->depth = 0;		
		return;
	}
}
void node::build(int _item)
{
	item=_item;
	strcpy(color,"blue");	
	lchild=rchild=NULL;
}
int node::get_data()
{
	return item;
}
void node::make_t(int _item, node nnode)
{
	
	if (this->item == -1) {
		this->item = _item;
		
		return;
	}
	if (this->item == _item){
		if (lchild == NULL) {
			
			this->lchild = (node*)malloc(sizeof(node));
			this->lchild->build(nnode.get_data());
			this->lchild->depth = this->depth + 1;
			
		}
		
		else {
			this->rchild = (node*)malloc(sizeof(node));
			this->rchild->build(nnode.get_data());
			this->rchild->depth = this->lchild->depth;

			
		}
		return;
	}
	if (this->lchild != NULL)		
		this->lchild->make_t(_item, nnode);
	if (this->rchild != NULL)	
		this->rchild->make_t(_item, nnode);
}

void node::inorder()//print
{
	if(this!=NULL){
		cout<<"["<<item<<"]";
		lchild->inorder();
		rchild->inorder();
		
	}
}
void node::Dinorder()//print
{
	if (this != NULL){
		cout << "[" << depth << "]";
		lchild->Dinorder();
		rchild->Dinorder();
		
	}
}
void node::Cinorder()
{
	if (this != NULL){
		cout << "[" << color << "]";
		lchild->Cinorder();
		rchild->Cinorder();

	}
}
void node::Order(int ti, int vi){
	
	if (ti == 1){
		nptr nnode;
		if (this == NULL)
			return;
		if (this->item == vi){
			if (strcmp(this->color, "red") == 0)
				cout << "이미 red입니다.\n";
			strcpy(this->color, "red");			
			return;
		}
		if (this->lchild != NULL && this->rchild == NULL){
			nnode = this->lchild;
			nnode->Order(ti, vi);
		}
		else if (this->lchild != NULL && this->rchild != NULL){
			nnode = this->lchild;
			nnode->Order(ti, vi);
			nnode = this->rchild;
			nnode->Order(ti, vi);
		}
	}

	else if (ti == 2){
		int viD;
		int redD;
		int dist; 
		viD = CountDepth(vi);
		redD = CountDepth2();			
		dist = viD - redD;
		
		if (dist < 0)
			dist = -dist;
		cout << dist << "\n";
	}
		return;
	
}

int node::CountDepth(int vi){
	nptr nnode = this;
	if (nnode == NULL)
		return 0;
	if (nnode->item == vi){
		return nnode->depth;
	}
	if (this->lchild != NULL && this->rchild == NULL){
		nnode = this->lchild;
		nnode->CountDepth(vi);
	}	
	else if (this->lchild != NULL&&this->rchild != NULL){
		nnode = this->lchild;
		nnode->CountDepth(vi);
		nnode = this->rchild;
		nnode->CountDepth(vi);
	}
}
int node::CountDepth2(){
	nptr nnode ;
	if (redSize() == 0)
		return 0;
	if (this == NULL)
		return 0;
	if (strcmp(this->color, "red") == 0)
		return this->depth;
	if (this->lchild != NULL && this->rchild == NULL){
		nnode = this->lchild;
		nnode->CountDepth2();
	}
	else if (this->lchild != NULL&&this->rchild != NULL){
		nnode = this->lchild;
		nnode->CountDepth2();
		nnode = this->rchild;
		nnode->CountDepth2();
	}
}

int node::redSize(){
	if (this != NULL){
		if (strcmp(this->color, "red") == 0)
			cnt++;

		lchild->redSize();
		rchild->redSize();
	}
	return cnt;
}