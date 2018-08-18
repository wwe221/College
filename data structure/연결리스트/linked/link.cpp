#include"link.h"
void StdInfo::build (int _id,char *_name, char *_dept, char *_city, double _gpa){
//this-> 셀프 레퍼런스. StdInfo build 안에 있는거 가리킴.
	id =_id;
	strcpy(name ,_name);	
	strcpy(dept ,_dept);	
	strcpy(city , _city);	
	gpa = _gpa;}
int StdInfo::getid(){return id;}
char *StdInfo::getname(){return name;}
char *StdInfo::getdept(){return dept;}
char *StdInfo::getcity(){return city;}
double StdInfo::getgpa(){return gpa;}
void node::build (StdInfo cStd){
	nptr chg= this;
	chg->id =cStd.getid();
	strcpy(chg->name ,cStd.getname());
	strcpy(chg->dept ,cStd.getdept());
	strcpy(chg->city ,cStd.getcity());
	chg->gpa = cStd.getgpa();}
void node::create(int _n){
	numb=_n;
	first=new node();
	dis=first;
	n=0;
}
void node::search ( char *name )
{	cout<<name<<"학생 검색\n";
	nptr chg = first->Rlink->Rlink;
	for(int i=0;i<numb-1;i++){
	if (strcmp(chg->name , name)==0){
		cout<<chg->id<<"\t"<<chg->name<<"\t"<<chg->dept<<"\t"<<chg->city<<"\t"<<chg->gpa<<"\n";break;}
	chg = chg->Rlink;}
	if(chg->Rlink==NULL){cout<<"그런 학생은 없습니다요\n";return;}

}
void node::inser(StdInfo cStd){	
	nptr nod= new node();
	nod->build(cStd);
	dis->Rlink=nod;
	nod->Rlink=NULL;
	dis=nod;
}
void node::insert(StdInfo cStd){
	nptr chg = this;//시작해서	
	if(n==0){//NULL일떄
		chg= new node();
		chg->build(cStd);
		chg->Rlink=NULL;
		dis->Rlink=chg;
		dis=chg;
		n++;}
	nptr adrr=first;
	while ( adrr->Rlink != NULL ) {//NULL일때 까지 adr증가
		if (strcmp(adrr->Rlink->name , cStd.getname())>0)
			break;
		adrr = adrr->Rlink;}
	nptr nnode = new node;
	nnode->build(cStd);	
	nnode->Rlink = adrr->Rlink;
	nnode->Llink = adrr;
	adrr->Rlink = nnode;
	adrr= nnode;}

void node::remove(char *name){
	cout<<name<<"학생 정보 지우기\n";
	nptr chg = first->Rlink;
	int n=0;
	for(int i=0;i<numb-1;i++){
		if ( strcmp(chg->Rlink->name , name)==0)
			break;
		chg = chg->Rlink;n++;}
	if(chg->Rlink==NULL){cout<<"그런 학생은 없습니다요\n\n";return;}
	nptr dnode = chg->Rlink;
	chg->Rlink = dnode->Rlink;		
	free ( dnode );
	numb--;
	cout<<"성공적으로 삭제했습니다.\n\n";
	}
void node::print(){
	cout<<"학번\t\t이름\t학과\t도시\t학점\n";
	nptr temp=first->Rlink->Rlink;
	for(int i=0;i<numb-1;i++){
	cout<<temp->id<<"\t"<<temp->name<<"\t"<<temp->dept<<"\t"<<temp->city<<"\t"<<temp->gpa<<"\n";
	temp=temp->Rlink;}}
void node::queqtion_five(){
	cout<<"최고 평점학생 찾기\n";
	nptr chg = first;
	double gp=first->gpa;
	char nam[10];	
	strcpy(nam,first->name);
	while(chg->Rlink!=NULL){
		if(chg->Rlink->gpa>gp){
			gp=chg->Rlink->gpa;
			strcpy(nam,chg->Rlink->name);}
		chg=chg->Rlink;}
	cout<<"최고 평점 학생은"<<gp<<"점을 기록한"<<nam<<"입니다.\n\n";
			
}
void node::queqtion_six(){
	cout<<"전체학생의 평점 평균\n";
	double a,aver;
	nptr chg = first;
	while(chg->Rlink!=NULL){
		a=a+chg->Rlink->gpa;
		chg=chg->Rlink;}
	aver=a/numb;
	cout<<"전체학생의 평균 평점은"<<aver<<"점 입니다\n\n";
}
void node::queqtion_seven(char *city){
	cout<<"일산 사는사람 찾기\n";
	int a=0;
	nptr chg = first->Rlink;
	while(chg->Rlink!=NULL){
		if(strcmp(chg->city,city)==0)
			a++;
		chg=chg->Rlink;}
	cout<<city<<"에 사는 사람은"<<a<<"명 입니다.\n\n";
}