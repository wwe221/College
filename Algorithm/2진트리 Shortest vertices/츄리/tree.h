#ifndef _TREE_H_
#define _TREE_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<iostream>
using namespace std;

typedef class node *nptr;
static int cnt = 0;

class node{
	int item;
	int depth;
	char color[5];
	nptr lchild,rchild;
public:
	
	node(){item=-1;lchild=rchild=NULL;}
	void root(int _item);
	void build (int _item);
	void make_t(int _item,node nnode);	

	void inorder();
	void Dinorder();
	void Cinorder();

	int CountDepth(int vi);
	int CountDepth2();
	void Order(int ti, int vi);
	int redSize();
	
	int get_data();
	nptr get_lchild(){
		return lchild;}
	nptr get_rchild(){
		return rchild;}	
};

#endif