#ifndef _BST_H_
#define _BST_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef class node *nptr;
class node {
	int item;
	nptr lchild, rchild, mchild;

public:
	node ( ) {
		item = -1;
		lchild = rchild = NULL;
	}
	void build ( int _item ) {
		item = _item;
		lchild = rchild = NULL;
	}
	void insert ( int key );
	void search ( int key );
	void inorder ( );
};
#endif