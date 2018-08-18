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

class StdList{
	

public:
	int n;
	int cnt;
	StdInfo *list;
		void create (int _n);
		void insert (StdInfo cStd);
		void insertname (StdInfo cStd);
		void insertgpa (StdInfo cStd);
		void remove (char dname[10]);
		void bisearch(char sname[10]);
		void search(char sname[10]);
		void print ();
		int count();
};
#endif