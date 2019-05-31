#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <ainclude.hpp>
#include<stdlib.h>/*用到了srand函数，所以要有这个头文件*/
#include<time.h>

#define STACKSIZE 500

typedef int SqStackElemType;

struct SqStack
{
    SqStackElemType data[STACKSIZE];
    int top ;
};

void SqStackTest()
{
    printf("\n\n-----SqStackTest-----\n");

    SqStack S;
    S.top = -1;


    srand( time(NULL) );

    printf("\n\n-----push-----\n");
    for(int i = 0 ; i< 25 ; i++)
    {  
        S.data[++S.top] = rand()%1000;
         printf("S.data[%d]:%d \n", i,S.data[i] );
    }

    printf("\n\n-----pop-----\n");
    for(int i = 0 ; i< 5 ; i++)
    {  
         printf("S.data[%d]:%d \n", i,S.data[S.top--] );
    }

    printf("\n\n-----遍历-----\n");
    for(int i = 0 ; i<= S.top ;i++)
    {
        printf("S.data[%d]:%d \n", i,S.data[i] );
    }
}
#endif
