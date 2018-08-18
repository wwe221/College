#ifndef _TREE_H_
#define _TREE_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <fstream>
#include <iostream>
using namespace std;

typedef class node *nptr;
class node {
	int item;
	nptr lchild, rchild;
	int i;

public:
	node (int _item){item=_item;lchild=rchild=NULL;i=0;}
	void build ( int _item );
	int is_empty ( );
	void insert( int key );
	void search ( int key );
	int remove ( int key );
	void inorder();
	
};




















#endif