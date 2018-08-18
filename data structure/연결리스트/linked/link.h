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
	node(){id=0,gpa=0,strcpy(name,"��"),strcpy(dept,"��"),	strcpy(city,"��"),Rlink=0,Llink=0;}
	int numb;//���л���
	int n;
	void build(StdInfo cStd);
	void create(int _n);
	void inser(StdInfo tStd);
	void insert ( StdInfo tStd );
	void search( char *name );
	void remove ( char *name );
	void print( );
	void queqtion_five ( );//�ְ�����
	void queqtion_six ( );//��ü ���
	void queqtion_seven(char *city);//�ϻ��� �л� ���
	void queqtion_eight();//���帹�� �л��� �����ϴ� ����
	void queqtion_nine();//��� �а�,�а�����
};

#endif