#include"link.h"
void StdInfo::build (int _id,char *_name, char *_dept, char *_city, double _gpa){
//this-> ���� ���۷���. StdInfo build �ȿ� �ִ°� ����Ŵ.
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
{	cout<<name<<"�л� �˻�\n";
	nptr chg = first->Rlink->Rlink;
	for(int i=0;i<numb-1;i++){
	if (strcmp(chg->name , name)==0){
		cout<<chg->id<<"\t"<<chg->name<<"\t"<<chg->dept<<"\t"<<chg->city<<"\t"<<chg->gpa<<"\n";break;}
	chg = chg->Rlink;}
	if(chg->Rlink==NULL){cout<<"�׷� �л��� �����ϴٿ�\n";return;}

}
void node::inser(StdInfo cStd){	
	nptr nod= new node();
	nod->build(cStd);
	dis->Rlink=nod;
	nod->Rlink=NULL;
	dis=nod;
}
void node::insert(StdInfo cStd){
	nptr chg = this;//�����ؼ�	
	if(n==0){//NULL�ϋ�
		chg= new node();
		chg->build(cStd);
		chg->Rlink=NULL;
		dis->Rlink=chg;
		dis=chg;
		n++;}
	nptr adrr=first;
	while ( adrr->Rlink != NULL ) {//NULL�϶� ���� adr����
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
	cout<<name<<"�л� ���� �����\n";
	nptr chg = first->Rlink;
	int n=0;
	for(int i=0;i<numb-1;i++){
		if ( strcmp(chg->Rlink->name , name)==0)
			break;
		chg = chg->Rlink;n++;}
	if(chg->Rlink==NULL){cout<<"�׷� �л��� �����ϴٿ�\n\n";return;}
	nptr dnode = chg->Rlink;
	chg->Rlink = dnode->Rlink;		
	free ( dnode );
	numb--;
	cout<<"���������� �����߽��ϴ�.\n\n";
	}
void node::print(){
	cout<<"�й�\t\t�̸�\t�а�\t����\t����\n";
	nptr temp=first->Rlink->Rlink;
	for(int i=0;i<numb-1;i++){
	cout<<temp->id<<"\t"<<temp->name<<"\t"<<temp->dept<<"\t"<<temp->city<<"\t"<<temp->gpa<<"\n";
	temp=temp->Rlink;}}
void node::queqtion_five(){
	cout<<"�ְ� �����л� ã��\n";
	nptr chg = first;
	double gp=first->gpa;
	char nam[10];	
	strcpy(nam,first->name);
	while(chg->Rlink!=NULL){
		if(chg->Rlink->gpa>gp){
			gp=chg->Rlink->gpa;
			strcpy(nam,chg->Rlink->name);}
		chg=chg->Rlink;}
	cout<<"�ְ� ���� �л���"<<gp<<"���� �����"<<nam<<"�Դϴ�.\n\n";
			
}
void node::queqtion_six(){
	cout<<"��ü�л��� ���� ���\n";
	double a,aver;
	nptr chg = first;
	while(chg->Rlink!=NULL){
		a=a+chg->Rlink->gpa;
		chg=chg->Rlink;}
	aver=a/numb;
	cout<<"��ü�л��� ��� ������"<<aver<<"�� �Դϴ�\n\n";
}
void node::queqtion_seven(char *city){
	cout<<"�ϻ� ��»�� ã��\n";
	int a=0;
	nptr chg = first->Rlink;
	while(chg->Rlink!=NULL){
		if(strcmp(chg->city,city)==0)
			a++;
		chg=chg->Rlink;}
	cout<<city<<"�� ��� �����"<<a<<"�� �Դϴ�.\n\n";
}