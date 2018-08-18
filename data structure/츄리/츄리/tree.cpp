#include "tree.h"

void node::root(int _item)//인티져
{
	if ( this->item==-1) {
		this->item = _item;
		cout<<"루트";
		return;
	}
}
void node::croot(char *_item)//캐릭터
{
	if (strcmp(this->citem,"-1")==0) {
		strcpy(this->citem,_item);
		cout<<"루트";
		return;
	}

}
void node::build(int _item)//인티져
{
	item=_item;
	lchild=rchild=mchild=NULL;
}
void node::cbuild(char *_item)//캐릭터
{
	strcpy(citem,_item);
	lchild=rchild=mchild=NULL;
}
int node::get_data()//인티져/
{
	return item;
}
char *node::cget_data()//캐릭터
{
	return citem;
}
void node::make_t(int _item,node nnode)//인티져
{
	//1.루트노드 만들기
	if ( this->item==-1) {
		this->item = _item;
		cout<<"루트\n";
		return;
	}
	if (this->item==_item){
		if (lchild==NULL) { //왼쪽이 비어있으면
		//왼쪽에 삽입
			this->lchild = (node*)malloc(sizeof(node));
			this->lchild->build(nnode.get_data());
			cout<<"왼쪽삽입\n";
		}	

		else if(lchild!=NULL){ //왼쪽 차있으면서
			//오른쪽이 차있으면 가운데 삽입
			if ( this->rchild != NULL ) {
				this->mchild = (node*)malloc(sizeof(node));
				this->mchild->build(nnode.get_data());
				cout<<"가운데 삽입\n";
			}
			//오른쪽 비어있으면 오른쪽 삽입
			else {
				this->rchild = (node*)malloc(sizeof(node));
				this->rchild->build(nnode.get_data());
				cout<<"오른쪽 삽입\n";
			}
			}
	return;}
	if (this->lchild!=NULL)
		this->lchild->make_t(_item,nnode);

	if (this->rchild!=NULL)
		this->rchild->make_t(_item,nnode);
	if (this->mchild!=NULL)
		this->mchild->make_t(_item,nnode);
}
void node::make_ct(char *_item,node nnode)//캐릭터
{
	//1.루트노드 만들기
	if ( strcmp(this->citem,"-1")==0) {
		strcpy(this->citem,_item);
		cout<<"루트\n";
		return;
	}
	if (strcmp(this->citem,_item)==0){
		if (lchild==NULL) { //왼쪽이 비어있으면
		//왼쪽에 삽입
			this->lchild = (node*)malloc(sizeof(node));
			this->lchild->cbuild(nnode.cget_data());
			cout<<"왼쪽삽입\n";
		}	

		else if(lchild!=NULL){ //왼쪽 차있으면서
			//오른쪽이 차있으면 가운데 삽입
			if ( this->rchild != NULL ) {
				this->mchild = (node*)malloc(sizeof(node));
				this->mchild->cbuild(nnode.cget_data());
				cout<<"가운데 삽입\n";
			}
			//오른쪽 비어있으면 오른쪽 삽입
			else {
				this->rchild = (node*)malloc(sizeof(node));
				this->rchild->cbuild(nnode.cget_data());
				cout<<"오른쪽 삽입\n";
			}
		}
	return;}
	if (this->lchild!=NULL)
		this->lchild->make_ct(_item,nnode);

	if (this->rchild!=NULL)
		this->rchild->make_ct(_item,nnode);
	if (this->mchild!=NULL)
		this->mchild->make_ct(_item,nnode);


}
void node::make_tree(int _item,node lnode,node rnode)
{	
	/*0.예외 처리
	1.니가 item이냐 아니냐
	2.맞으면 왼쪽lnode,오른쪽rnode.
	3.아니면 lchild->make_tree*/
	if(this->item==-1){
		this->item=_item;
		this->lchild = (node*)malloc(sizeof(node));
		this->rchild = (node*)malloc(sizeof(node));
		this->lchild->build(lnode.get_data());
		this->rchild->build(rnode.get_data());
		cout<<"루트";
	}

	if (this->item==_item){
		this->lchild = (node*)malloc(sizeof(node));
		this->lchild->build(lnode.get_data());
		this->rchild = (node*)malloc(sizeof(node));
		this->rchild->build(rnode.get_data());
		return;
	}
	if (this->lchild!=NULL)
		this->lchild->make_tree(_item,lnode,rnode);

	if (this->rchild!=NULL)
		this->rchild->make_tree(_item,lnode,rnode);
}
void node::inorder()
{
	if(this!=NULL){
		cout<<"["<<citem<<"]";
		lchild->inorder();
		rchild->inorder();
		mchild->inorder();
	}
}
void node::print()//왕과 자식들 뽑기
{	
	if(is_empty())
		cout<<"비어 있습니다\n.";
	if(this==NULL)
		return;
	if(this!=NULL){
		if(this->lchild==NULL){
			cout<<citem<<endl;
			return;}
		else if(this->rchild==NULL){//왼쪽만 있을때
			cout<<citem<<"-"<<this->lchild->citem<<endl;
			lchild->print();
			
		}
		
		else if(this->mchild!=NULL){//셋다
			cout<<citem<<"-"<<this->lchild->citem<<","<<this->rchild->citem<<","<<this->mchild->citem<<endl;
			lchild->print();
			rchild->print();
			mchild->print();
		}
		else if(this->rchild!=NULL && this->mchild==NULL){
			cout<<citem<<"-"<<this->lchild->citem<<","<<this->rchild->citem<<endl;
			lchild->print();
			rchild->print();
		}
	}

}
void node::printt()//왕만 뽑기
{
	if(is_empty())
		cout<<"비어 있습니다\n.";
	if(this==NULL)
		return;
	if(this!=NULL){
		if(this->lchild==NULL){
			cout<<citem<<endl;
			return;}
		else if(this->rchild==NULL){//왼쪽만 있을때
			cout<<citem<<endl;
			lchild->printt();
			
		}
		
		else if(this->mchild!=NULL){//셋다
			cout<<citem<<endl;
			lchild->printt();
			rchild->printt();
			mchild->printt();
		}
		else if(this->rchild!=NULL && this->mchild==NULL){
			cout<<citem<<endl;
			lchild->printt();
			rchild->printt();
			
		}
	}
}
void node::revprint()
{
	if(is_empty())
		cout<<"비어 있습니다\n.";
	if(this==NULL)
		return;
	if(this!=NULL){
		if(this->lchild==NULL){
			cout<<citem<<endl;
			return;}
		
		else if(this->rchild==NULL){//왼쪽만 있을때
			
			lchild->revprint();
			
			
			cout<<citem<<endl;
		}
		
		else if(this->mchild!=NULL){//셋다
			mchild->revprint();
			rchild->revprint();
			lchild->revprint();			
			
			cout<<citem<<endl;
		}
		else if(this->rchild!=NULL && this->mchild==NULL){
			
			rchild->revprint();
			lchild->revprint();						
			cout<<citem<<endl;
		}

		
		
	}
}
void node::countking()
{
	if(is_empty())
		cout<<"비어 있습니다\n.";
	if(this==NULL)
		return;
	if(this!=NULL){
		if(this->lchild==NULL){
			cnt++;
			return;}
		else if(this->rchild==NULL){//왼쪽만 있을때
			cnt++;
			lchild->countking();
		}
		
		else if(this->mchild!=NULL){//셋다
			cnt++;			
			lchild->countking();
			rchild->countking();
			mchild->countking();
		}
		else if(this->rchild!=NULL && this->mchild==NULL){
			cnt++;			
			lchild->countking();
			rchild->countking();
			
		}
	}
}

void node::injo()
{	
	if(is_empty())
		cout<<"비어 있습니다\n.";
	if(strcmp(this->citem,"인조")==0){
		if(this->rchild==NULL)//왼쪽만 있을때
			this->lchild->print();
		else if(this->mchild!=NULL){
			this->lchild->print();
			this->rchild->print();
			this->mchild->print();
		}
		else if(this->rchild!=NULL && this->mchild==NULL){
			this->lchild->print();
			this->rchild->print();
		}
	}


	else
		if(this->lchild==NULL){
			return;}
		else if(this->rchild==NULL){//왼쪽만 있을때
			lchild->injo();
			
		}
		
		else if(this->mchild!=NULL){//셋다
			lchild->injo();
			rchild->injo();
			mchild->injo();
		}
		else if(this->rchild!=NULL && this->mchild==NULL){
			lchild->injo();
			rchild->injo();
	}
}
void node::sonnotking()
{
	if(is_empty())
		cout<<"비어 있습니다\n.";
	if(this!=NULL){
		if(this->lchild==NULL)
			cout<<this->citem<<endl;
		else if(this->rchild==NULL){//왼쪽만 있을때
			lchild->sonnotking();
		}
		
		else if(this->mchild!=NULL){//셋다
			lchild->sonnotking();
			rchild->sonnotking();
			mchild->sonnotking();
		}
		else if(this->rchild!=NULL && this->mchild==NULL){
			lchild->sonnotking();
			rchild->sonnotking();
			
		}
	}
}
void node::mostsonking()
{
	if(is_empty())
		cout<<"비어 있습니다\n.";
	if(this!=NULL){
		if(this->lchild==NULL)
			return;
		else if(this->rchild==NULL){//왼쪽만 있을때
			lchild->mostsonking();
		}
		
		else if(this->mchild!=NULL){//셋다
			cout<<this->citem<<endl;
			lchild->mostsonking();
			rchild->mostsonking();
			mchild->mostsonking();
		}
		else if(this->rchild!=NULL && this->mchild==NULL){
			
			lchild->mostsonking();
			rchild->mostsonking();
			
		}
	}
}
void node::jjbro()
{
	if(is_empty())
		cout<<"비어 있습니다\n.";

	if(strcmp(this->lchild->citem,"정종")==0  || strcmp(this->rchild->citem,"정종")==0  || strcmp(this->mchild->citem,"정종")==0 )
	{
		if(strcmp(this->lchild->citem,"정종")==0 && this->rchild==NULL){
			cout<<"정종은 형제가 없습니다.";
			return;
		}
		else if(strcmp(this->lchild->citem,"정종")==0 && this->rchild!=NULL && this->mchild==NULL){
			cout<<this->rchild->citem<<endl;
			return;
		}
		else if(strcmp(this->rchild->citem,"정종")==0 && this->mchild==NULL){
			cout<<this->lchild->citem<<endl;
			return;
		}
		else if(strcmp(this->mchild->citem,"정종")==0){
			cout<<this->lchild->citem<<","<<this->rchild->citem<<endl;
			return;
		}
	}
	else{
		if(this!=NULL){
			if(this->lchild==NULL)
				return;
			else if(this->rchild==NULL){//왼쪽만 있을때
				lchild->jjbro();
			}
			
			else if(this->mchild!=NULL){//셋다
				lchild->jjbro();
				rchild->jjbro();
				mchild->jjbro();
			}
			else if(this->rchild!=NULL && this->mchild==NULL){
				
				lchild->jjbro();
				rchild->jjbro();			
			}
		}
	}
}
int node::soonfathers()
{
	if(is_empty())
		cout<<"비어 있습니다\n.";
	item=this->soonsearch();
	if(item){
		cout<<this->citem<<endl;
		return 1;}

	if(this!=NULL){	
		if (this->lchild==NULL)
			return 0;
		else if(this->rchild==NULL){//왼쪽만 있을때
			int tt;
			tt=lchild->soonfathers();
			if(tt){
				cout<<this->citem<<endl;
				return 1;}
		}
		
		else if(this->mchild!=NULL){//셋다
			int t1,t2,t3;
			t3=mchild->soonfathers();
			t2=rchild->soonfathers();
			t1=lchild->soonfathers();
			
			
			if(t1+t2+t3){
				cout<<this->citem<<endl;
				return 1;}
		}
		else if(this->rchild!=NULL && this->mchild==NULL){
			int t1,t2;
			t2= rchild->soonfathers();
			t1=	lchild->soonfathers();
			
			if(t1+t2){
				cout<<this->citem<<endl;
				return 1;}			
		}
	}
	return 0;
}
int node::soonsearch()
{	
	if(this->item==1)
		return 1;
	
	if(lchild==NULL)
		return 0;
	if(mchild!=NULL){
		if(strcmp(lchild->citem,"순종")==0){
			
			return 1;
		}//자식에 순종이 있으면 1리턴
		else if(strcmp(rchild->citem,"순종")==0){
			
			return 1;
		}
		else if(strcmp(mchild->citem,"순종")==0 ){
			
			return 1;
		}
		else {
			
			return 0;
		}
	}
	else if(rchild!=NULL && mchild==NULL){
		if(strcmp(lchild->citem,"순종")==0){
		
			return 1;
		}//자식에 순종이 있으면 1리턴
		else if(strcmp(rchild->citem,"순종")==0){
		
			return 1;
		}
		else {
		
			return 0;
		}
	}
	else if(lchild!=NULL && rchild==NULL){
		if(strcmp(lchild->citem,"순종")==0){
			
			return 1;
		}//자식에 순종이 있으면 1리턴
		else {
			
			return 0;
		}
	}
}
void node::twosonking()
{
	if(is_empty())
		cout<<"비어 있습니다\n.";
	if(this!=NULL){
		if(this->lchild==NULL)
			return;
		else if(this->rchild==NULL){//왼쪽만 있을때
			lchild->twosonking();
		}
		
		else if(this->mchild!=NULL){//셋다
			cnt++;
			lchild->twosonking();
			rchild->twosonking();
			mchild->twosonking();
		}
		else if(this->rchild!=NULL && this->mchild==NULL){
			cnt++;
			lchild->twosonking();
			rchild->twosonking();
			
		}
	}
}
int node::howdae()
{		
	if(is_empty())
		cout<<"비어 있습니다\n.";

	if(strcmp(this->citem,"태종")==0)
		tae=1;
	if(tae){
	item=this->yeah();
	if(item){
		cout<<this->citem<<endl;
		cnt++;
		return 1;}

	if(this!=NULL){	
		if (this->lchild==NULL)
			return 0;
		else if(this->rchild==NULL){//왼쪽만 있을때
			int tt;
			tt=lchild->howdae();
			if(tt){
				cout<<this->citem<<endl;
				cnt++;
				return 1;}
		}
		
		else if(this->mchild!=NULL){//셋다
			int t1,t2,t3;
			t3=mchild->howdae();
			t2=rchild->howdae();
			t1=lchild->howdae();
			
			
			if(t1+t2+t3){
				cout<<this->citem<<endl;
				cnt++;
				return 1;}
		}
		else if(this->rchild!=NULL && this->mchild==NULL){
			int t1,t2;
			t2= rchild->howdae();
			t1=	lchild->howdae();
			
			if(t1+t2){
				cout<<this->citem<<endl;
				cnt++;
				return 1;}			
		}
	}
	return 0;
	}
	else
		if(this!=NULL){	
		if (this->lchild==NULL)
			return 0;
		else if(this->rchild==NULL){//왼쪽만 있을때
			lchild->howdae();
			
		}
		
		else if(this->mchild!=NULL){//셋다
			
			mchild->howdae();
			rchild->howdae();
			lchild->howdae();			
		}
		else if(this->rchild!=NULL && this->mchild==NULL){
			rchild->howdae();
			lchild->howdae();					
		}
	}
}
int node::yeah()
{
	if(this->item==1)
		return 1;
	
	if(lchild==NULL)
		return 0;
	if(mchild!=NULL){
		if(strcmp(lchild->citem,"예종")==0){
			
			return 1;
		}//자식에 순종이 있으면 1리턴
		else if(strcmp(rchild->citem,"예종")==0){
			
			return 1;
		}
		else if(strcmp(mchild->citem,"예종")==0 ){
			
			return 1;
		}
		else {
			
			return 0;
		}
	}
	else if(rchild!=NULL && mchild==NULL){
		if(strcmp(lchild->citem,"예종")==0){
		
			return 1;
		}//자식에 예종이 있으면 1리턴
		else if(strcmp(rchild->citem,"예종")==0){
		
			return 1;
		}
		else {
		
			return 0;
		}
	}
	else if(lchild!=NULL && rchild==NULL){
		if(strcmp(lchild->citem,"예종")==0){
			
			return 1;
		}//자식에 예종이 있으면 1리턴
		else {
			
			return 0;
		}
	}
}
int node::is_empty()
{
		if(strcmp(citem,"-1")==0) 
			return 1; 
		else 
			return 0;
}
void node::get_cnt()//카운트 출력
{	
	cout<<" "<<cnt;
	cnt=0;
}