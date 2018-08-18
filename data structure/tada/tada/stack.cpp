#include "stack.h"
#include<string>
void StdInfo::build ( int _id, char *_name, char *_dept, char *_city, float _gpa ){
	id =_id;
	strcpy(name ,_name);	
	strcpy(dept ,_dept);	
	strcpy(city , _city);	
	gpa = _gpa;} 


void StdStack::create ( int _n ){
	n=_n;
	Top=-1;
	stack= new StdInfo[_n];
	if(stack==NULL)
		cout<<"공간 할당 실패함.";
}


void StdStack::Push( StdInfo cStd ){
	stack[++Top].build(cStd.id, cStd.name, cStd.dept, cStd.city, cStd.gpa);
}


int StdStack::is_full ( ){
	return (Top==n-1);
}

int	StdStack::is_empty(){
	return (Top==-1);
}


StdInfo StdStack::Pop( ){
	return stack[Top--];

}

