#include "list.h"
#include<string>
void StdInfo::build (int _id,char *_name, char *_dept, char *_city, double _gpa){
//this-> 셀프 레퍼런스. StdInfo build 안에 있는거 가리킴.
	id =_id;
	strcpy(name ,_name);	
	strcpy(dept ,_dept);	
	strcpy(city , _city);	
	gpa = _gpa;} 
void StdList::create(int _n){
	n=_n;
	list =new StdInfo[_n];
	cnt=0;}

void StdList::insert(StdInfo cStd){
	list[cnt].build(cStd.id,cStd.name,cStd.dept,cStd.city,cStd.gpa);
		cnt++;}
void StdList::insert_gpa (StdInfo cStd){
	int k,p;
	p=0;
	for(k=0;k<=cnt;k++){
		if(list[k].gpa<cStd.gpa)
			break;}
	p=k;
			for(int ii=cnt;ii>p;ii--)
				list[ii].build(list[ii-1].id,list[ii-1].name,list[ii-1].dept,list[ii-1].city,list[ii-1].gpa);
	list[p].build(cStd.id,cStd.name,cStd.dept,cStd.city,cStd.gpa);
	cnt++;}


void StdList::insert_name(StdInfo cStd){
	int k,p;
	p=0;
	for(k=0;k<=cnt;k++){
		if(strcmp(list[k].name,cStd.name)==1)
			break;}
	p=k;
			for(int ii=cnt;ii>p;ii--)
				list[ii].build(list[ii-1].id,list[ii-1].name,list[ii-1].dept,list[ii-1].city,list[ii-1].gpa);
	list[p].build(cStd.id,cStd.name,cStd.dept,cStd.city,cStd.gpa);
	cnt++;}
void StdList::remove(char dname[10]){
	cout<<"학생정보 삭제\n";
	int i=0;
	string ex1,ex2;
	ex1=dname;
		while(i<n){
ex2=list[i].name;
			if(ex1==ex2){
				for(int ii=i;ii<cnt-1;ii++)
				list[ii].build(list[ii+1].id,list[ii+1].name,list[ii+1].dept,list[ii+1].city,list[ii+1].gpa);				
				cnt--;
				cout<<dname<<"의 정보가 성공적으로 삭제되었습니다.\n\n\n";
				return;}
			else i++;}
		if(i=n+1){cout<<dname<<"은(는) 수강학생 명단에 존재하지 않습니다\n";cout<<"\n\n\n\n";}
}	
void StdList::bisearch(char sname[10]){
	cout<<"이진검색\n";
	int fir=0;
	int last=n-1;
	int mid;	
	string ex1,ex2;
	ex1=sname;
	while(fir<=last){
		mid=(fir+last)/2;
		ex2=list[mid].name;
		if(ex1==ex2){
			cout<<list[mid].id<<"	"<< list[mid].name<<"	"<< list[mid].dept<<"	"<< list[mid].city<<"	"<< list[mid].gpa<<endl;
			cout<<"\n\n\n\n";
			return;}
		else if (ex1>ex2)
			fir=mid+1;
		else if (ex1<ex2)
			last=mid-1;
		}
	if(fir>=last){cout<<sname<<"은(는) 수강학생 명단에 존재하지 않습니다\n";cout<<"\n\n\n\n";}
	return ;
}
void StdList::search(char sname[10]){
		cout<<"순차적 검색\n";
		int i=0;
		while(i<n){
			if(strcmp(sname,list[i].name)==0){
				cout<<list[i].id<<"	"<< list[i].name<<"	"<< list[i].dept<<"	"<< list[i].city<<"	"<< list[i].gpa<<endl;
				cout<<"\n\n\n\n";
				return;}
			else i++;}
		if(i=n+1){cout<<sname<<"은(는) 수강학생 명단에 존재하지 않습니다\n";cout<<"\n\n\n\n";}
}


void StdList::print(){
	cout<<"번호	학번		이름	학과	거주지	학점\n";
	for(int i=0;i<cnt;i++){
		
		cout<<i+1<<"	"<<list[i].id<<"	"<< list[i].name<<"	"<< list[i].dept<<"	"<< list[i].city<<"	"<< list[i].gpa<<endl;}
	cout<<"\n\n\n\n";
}

