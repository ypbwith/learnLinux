#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <ainclude.hpp>
#include<stdlib.h>/*用到了srand函数，所以要有这个头文件*/
#include<time.h>
#include <aBiTree.hpp>

#define QUEUEMAXSIZE 50

typedef int QueueElemType ;
// typedef BiTNode QueueElemType ;

typedef struct 
{
	QueueElemType data[QUEUEMAXSIZE];
	int front,rear;
} SqQueue;

void initQueue( SqQueue &Q )
{
	Q.front = 0;
	Q.rear = 0;
}

bool queueIsEmpty(SqQueue Q)
{
	if(Q.rear == Q.front)
		return true;
	else
		return false;
}

bool enQueue(SqQueue &Q,QueueElemType x)
{
	if((Q.rear + 1)%QUEUEMAXSIZE == Q.front)
		return false;

	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1)%QUEUEMAXSIZE;

	return true;
}

int queueSize(SqQueue &Q )
{
	return (Q.rear - Q.front + QUEUEMAXSIZE)%QUEUEMAXSIZE;
}

bool deQueue(SqQueue &Q,QueueElemType &x)
{
	if( Q.rear == Q.front )
		return false;

	x = Q.data[Q.front];
	Q.front= (Q.front + 1)%QUEUEMAXSIZE;

	return true;

}

typedef BiTNode LinkQueueElemType;

struct LinkNode
{   
	LinkQueueElemType data;
	struct LinkNode * next;
};

struct LinkQueue
{
	struct LinkNode *front,*rear;	
} ;

void initLinkQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

bool linkQueueIsEmpty(LinkQueue &Q)
{
	if(Q.rear == Q.front)
		return true;
	else
		return false;
}

void enLinkQueue(LinkQueue &Q,LinkQueueElemType x)
{
	LinkNode * s = (LinkNode *)malloc (sizeof(LinkNode));
	s->data = x ;
	s->next = NULL;
	Q.rear->next= s; //rear 是最后一个指针先将rear所指向的数据结点的next赋值s,rear 在往后移动
	Q.rear = s; //
	// printf("%x \n", (void *)Q.rear->next);
}

bool deLinkQueue(LinkQueue &Q,LinkQueueElemType &x)
{
	if(Q.front == Q.rear) //判断linkQueue是否为空
		return false;
	LinkNode *p =Q.front->next; //由p保存头结点的后继
	x = p->data; //取头指针的后继的数据
    Q.front->next = p->next; //把后继的next缀到头的后面
	if(Q.rear == p) //如果只有一个数据结点就空了把rear和front置为同一
		Q.rear = Q.front;
	free(p); //释放第一个数据结点空间
	return true;
}

// void lqTest()
// {
// 	printf("\n-----链表队列-----\n");

// 	SqQueue Q;
//     initQueue(Q);

//     LinkQueue linkQ;

//     initLinkQueue( linkQ);
//     printf("linkQ.rear(%X) \n",(void *)linkQ.rear);

//     LinkQueueElemType x_0; 
//     QueueElemType x;

//     printf("\n-----enQueue-----\n");

//     srand( time(NULL) );
//     for(int i = 0 ; i< 10 ; i++)
//     {  

//         x_0 = rand() % 100 ;

//     	enLinkQueue(linkQ,x_0);
//     	printf("linkQ.front(%X) linkQ.rear(%X)  %d \n" ,(void *)linkQ.front,(void *)linkQ.rear,x_0);
//     }
    
 
//     for(int i = 0 ;i < 5 ;i++ )
//     {
//     	 deLinkQueue(linkQ,x_0);
//     }
  

//     printf("\n-----遍历-----\n");

//     LinkNode *p = linkQ.front->next;

//     while(p)
//     {
//     	x_0 = p->data;
//     	printf("%d ",x_0);
//     	p = p->next;
//     }

// }


void sqTest()
{
	printf("\n-----循环队列-----\n");
	SqQueue Q;
    initQueue(Q);

    QueueElemType x;

    printf("\n-----enQueue-----\n");
    srand( time(NULL) );

    for(int i = 0 ; i< 10 ; i++)
    {  
        x = rand() % 100 ;

        printf("front(%d) rear(%d) %d \n",Q.front,Q.rear,x);
    	enQueue( Q ,  x );
    }
    
    printf("\n\n-----deQueue-----\n");

    for(int i = 0 ;i < 5 ;i++ )
    {   
    	deQueue(Q ,x);
    	printf("front(%d) rear(%d) %d \n",Q.front,Q.rear,x);
    }

    printf("\n-----遍历-----\n");

    for(int i = 0 ;i < queueSize (Q) ;i++ )
    {
    	printf("%d ",Q.data[(Q.front + i) % QUEUEMAXSIZE]);
    }

}
#endif
