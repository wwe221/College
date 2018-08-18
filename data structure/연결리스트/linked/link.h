#ifndef _LIST_H_
#define _LIST_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <fstream>
#include <iostream>
using namespace std;

class StdInfo {	

	int id;
	char name[10];
	char dept[10];
	char city[10];
	double gpa;

public:
	int getid();
	char *getname();
	char *getdept();
	char *getcity();
	double getgpa();
	void build( int _id, char*_name, char *_dept, char *_city,double _gpa);};

typedef class node *nptr;

class node {
	
	int id;
	char name[10];
	char dept[10];
	char city[10];
	double gpa;
	nptr Llink,Rlink;
	nptr dis,first,adr;
	
public:
	node(){id=0,gpa=0,strcpy(name,"ㅋ"),strcpy(dept,"ㅋ"),	strcpy(city,"ㅋ"),Rlink=0,Llink=0;}
	int numb;//총학생수
	int n;
	void build(StdInfo cStd);
	void create(int _n);
	void inser(StdInfo tStd);
	void insert ( StdInfo tStd );
	void search( char *name );
	void remove ( char *name );
	void print( );
	void queqtion_five ( );//최고점수
	void queqtion_six ( );//전체 평균
	void queqtion_seven(char *city);//일산사는 학생 몇명
	void queqtion_eight();//가장많은 학생이 거주하는 도시
	void queqtion_nine();//몇개의 학과,학과종류
};

#endif