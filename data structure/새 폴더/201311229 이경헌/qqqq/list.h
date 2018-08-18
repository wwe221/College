#ifndef _LIST_H_
#define _LIST_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <fstream>
#include <iostream>
using namespace std;

 class StdInfo {
	
public:
	int id;
	char name[10];
	char dept[10];
	char city[10];
	double gpa;
	void build( int _id, char*_name, char *_dept, char *_city,double _gpa);};

class Stdstd {
public:
	char city[10];
	char dept[10];
	int cntC;//도시 사람
	int cntD;//학과 사람
};

class StdList{
public:
	double aver;//평점평균
	int count;//조건을 만족하는 사람의 수
	char ch;//비교대상
	int n;//총학생수
	int cnt;//등록된 학생수
	StdInfo *list;
	Stdstd *listt;
		void create (int _n);
		void insert (StdInfo cStd);
		void insert_name (StdInfo cStd);
		void insert_gpa (StdInfo cStd);
		void remove (char dname[8]);
		void bisearch(char sname[8]);
		void search(char sname[8]);
		void print ();
		void bestGpa();//1
		void worstGpa();//2
		void averGpa();//3
		void over4();//4
		void kim();//5
		void ilsan();//6
		void cityp();//7
};
#endif