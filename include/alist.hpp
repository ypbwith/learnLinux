#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <ainclude.hpp>
#include<stdlib.h>/*用到了srand函数，所以要有这个头文件*/
#include<time.h>

#define SeqMaxSize 50

typedef int SeqElemType ;

struct SqList
{
	SeqElemType *data;//此为动态，静态是在创建时分配，这需要动态的开辟空间
	int MaxSize,length;	
};

bool initSqList(SqList &S,unsigned int MaxSize)
{
	S.data = (SeqElemType *)malloc(sizeof(SeqElemType)*MaxSize);
	S.MaxSize = MaxSize;
	S.length = 0;
}

bool listInsert(SqList &S,int i , SeqElemType x)
{
	if ( i  > S.MaxSize - 1)
	{
		return false;
	}

	for(int j = S.length ; j > i ;j--)  //从0开始
	{
		S.data[j] = S.data[j - 1];
	}

	S.data[i] = x;
	S.length ++;

    printf("S.data[%d]:%d \n", i,S.data[i] );

	return true;
}

void SqListTest()
{
	printf("\n\n-----SqListTest-----\n");

	SqList S;
	initSqList(S,50);

   	srand( time(NULL) );

    for(int i = 0 ; i< 25 ; i++)
    {  
        listInsert( S, i ,rand()%1000);
    }

	for(int i = 0 ; i<S.length ;i++)
	{
		printf("S.data[%d]:%d \n", i,S.data[i] );
	}

	printf("\nS.MaxSize:%d S.length:%d \n", S.MaxSize,S.length);
}

typedef int LinkListElemType;

struct LinkListNode
{
	LinkListElemType data;
	struct LinkListNode *next;
};

struct LinkList
{
	LinkListNode *head; //与队列不同队列有front 和 rear
	int length;
};

LinkList CreatLinkListFront(LinkList &L)
{
	LinkListNode *s;
	LinkListElemType x;
	L.head = (LinkListNode *)malloc(sizeof(LinkListNode));
    L.head->next = NULL;
    printf("\ninput(int end of 9999):\n");
    scanf("%d",&x);
    while(x!=9999)
    {
    	s =  (LinkListNode *)malloc(sizeof(LinkListNode)); 
    	s->data = x;
    	s->next = L.head->next;
    	L.head->next = s;

        printf("\ninput(int end of 9999):\n");
    	scanf("%d",&x);
    }

    return L;
}

LinkList CreatLinkListRear(LinkList &L)
{
	LinkListNode *s,*r;
	LinkListElemType x;

	L.head = (LinkListNode *)malloc(sizeof(LinkListNode));
    L.head->next = NULL;
    s = r = L.head;

    printf("\ninput(int end of 9999):");
    scanf("%d",&x);
    while(x!=9999)
    {
    	s =  (LinkListNode *)malloc(sizeof(LinkListNode)); 
    	s->data = x;
    	r->next = s;
    	r = s;

        printf("\ninput(int end of 9999):");
    	scanf("%d",&x);
    }

    r->next = NULL;

    return L;
}

void LinkListTest()
{
	printf("\n\n-----LinkListTest-----\n\n");

	// LinkList L = CreatLinkListFront(L);
	LinkList L = CreatLinkListRear(L);

    printf("\n-----遍历-----\n");

    LinkListNode *p = L.head->next;
    LinkListElemType x ;
    while(p)
    {
    	x = p->data;
    	printf("input is %d \n",x);
    	p = p->next;
    }

}

#endif 
