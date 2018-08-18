#ifndef _TREE_H_
#define _TREE_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<iostream>
using namespace std;
typedef class node *nptr;
static int cnt=0;
static int tae=0;
class node{
	int item;
	char citem[10];	
	nptr lchild,rchild,mchild;
public:
	node(){item=-1;strcpy(citem,"-1");lchild=rchild=mchild=NULL;}
	void root(int _item);
	void build (int _item);	
	void make_t(int _item,node nnode);
	int get_data();
	void croot(char *_item);
	void cbuild(char *_item);	
	void make_ct(char *_item,node nnode);
	char *cget_data();

	void make_tree(int _item,node lnode,node rnode);
	void inorder();

	void print();//50점까지.
	int is_empty();
	void printt();//1
	void revprint();//2
	void countking();void get_cnt();//3
	void injo();//4
	void sonnotking();//5
	void mostsonking();//6
	void jjbro();//7
	int soonfathers();//8
	int soonsearch();//8번 보조.
	void twosonking();//9
	int howdae();//10
	int yeah();//10번 보조

	nptr get_lchild(){
		return lchild;}
	nptr get_rchild(){
		return rchild;}	
};

#endif