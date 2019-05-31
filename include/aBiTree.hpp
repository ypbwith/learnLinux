#ifndef _BITREE_HPP_
#define _BITREE_HPP_

#include <ainclude.hpp>

typedef int BiTreeElemType;

struct BiTNode
{
	BiTreeElemType data;
	struct BiTNode *lchild,*rchild;

};

struct BiTree
{
	BiTNode *root;
	BiTNode *p;
};

void visitBiTree(BiTree T)
{
	//对结点的操作
	;
}

void levelOrder(BiTree T)
{
	// LinkQueue Q;
	// initLinkQueue(Q);
}

#endif
