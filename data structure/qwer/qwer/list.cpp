#include "list.h"
void StdInfo::build (int _id,char *_name, char *_dept, char *_city, double _gpa){
//this-> 셀프 레퍼런스. StdInfo build 안에 있는거 가리킴.
	id =_id;
	strcpy(name ,_name);	
	strcpy(dept ,_dept);	
	strcpy(city , _city);	
	gpa = _gpa;} 
void StdList::create(int _n){
	n=_n;
	list =new StdInfo[_n+1];
	cnt=0;}

void StdList::insert(StdInfo cStd){	
	list[cnt].build(cStd.id,cStd.name,cStd.dept,cStd.city,cStd.gpa);
		cnt++;}

void StdList::insertname(StdInfo cStd){//미완
	int i,k=0, result;

	for(i=0;i<n;i++)
	{result = strcmp(list[i].name,cStd.name);
	list[cnt].build(cStd.id,cStd.name,cStd.dept,cStd.city,cStd.gpa);
	if(result == -1)break;k=i;
	for(int ii=cnt-1;ii>=k+1;ii--)
		list[ii].build(list[ii-1].id,list[ii-1].name,list[ii-1].dept,list[ii-1].city,list[ii-1].gpa);
	list[k].build(cStd.id,cStd.name,cStd.dept,cStd.city,cStd.gpa);
	
	}cnt++;}

void StdList::insertgpa(StdInfo cStd){
	for(int i=0;i<n;i++);
}
void StdList::remove(char dname[10]){
	}
void StdList::bisearch(char sname[10]){
	int fir=0;
	int last=n-1;
	int mid;
	while(fir<=last){
		mid=(fir+last)/2;
		if(sname==list[mid].name){
			cout<<list[mid].id<<"	"<< list[mid].name<<"	"<< list[mid].dept<<"	"<< list[mid].city<<"	"<< list[mid].gpa<<endl;}
		else if (sname>list[mid].name){
			fir=mid+1;
			StdList::bisearch(sname);}
		else{last=mid-1;
		StdList::bisearch(sname);
		}}}
void StdList::search(char sname[10]){		
		int i=0;
		while(i<n){
			if(sname==list[i].name){				
			cout<<list[i].id<<"	"<< list[i].name<<"	"<< list[i].dept<<"	"<< list[i].city<<"	"<< list[i].gpa<<endl;
	}	else i++;}
	cout<<sname<<"은(는) 수강학생 명단에 존재하지 않습니다\n";
}


void StdList::print(){
	for(int i=0;i<n-1;i++){
		cout<<list[i].id<<"	"<< list[i].name<<"	"<< list[i].dept<<"	"<< list[i].city<<"	"<< list[i].gpa<<endl;}
}