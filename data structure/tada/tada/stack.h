#ifndef _STACK_H_
#define _STACK_H_
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
	float gpa;
	void build ( int _id, char *_name, char *_dept, char *_city, float _gpa );
	void print ( ){cout<<id<<name<<dept<<city<<gpa;}

};

class StdStack {
	
public:
	int n; // Stack의 길이
	int Top; // Stack Top
	StdInfo *stack; // 동적 배열을 이용한 Stack 구현
	void create ( int _n );
	void Push( StdInfo cStd );
	int is_full ( );
	int	is_empty ( );
	StdInfo Pop( );

};
#endif