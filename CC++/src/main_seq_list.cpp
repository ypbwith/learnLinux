#include <stdlib.h>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <regex>
#include <malloc.h>

using namespace std;

#define bool int
#define True 1
#define False 0
#define ERROR -1
#define SIZE 100

/*
1,初始化现象表
2,删除线性表
3,判断是否为空表
4,线性表长度
5,输出线性表全部元素
6,按元素位置查找
7,按元素值查找
8,插入
9,删除
10,在末尾添加值
11,删除位置
*/

typedef struct {
    int data [SIZE];
    int length;
}seq_list;

void init_list(seq_list * list)
{
    list = (seq_list *)malloc(sizeof(seq_list));
    list->length = 0;
}

void destroy_list(seq_list *list)
{
    free (list);
}

void disp_list(seq_list * list)
{
    int i;
    for(i == 0;i< list->length;i++)
    {
        printf("%d ",list->data[i]);
    }
}

bool list_isEmpty(seq_list * list)
{
    return (list->length == 0);
}

int list_length(seq_list * list)
{
    return list->length;
}

int get_elem(seq_list * list,int key)
{
    int value = ERROR;

    if (-1 <key && key < list->length)
    {
        value = list->data[key];
    }
    return value;
}

int locate_elem(seq_list * list,int value)
{
    int key = -1;
    int i;
    for(i = 0;i<list->length;i++)
    {
        if(list->data[i] == value)
        {
            key = i;
            break;
        }

    }
    return key;
}

//插入value到key位置
bool list_insert(seq_list* list,int value ,int key)
{
    int i;
    if ((list->length < SIZE) && (-1 < key && key < list->length))
    {
        for (i = list->length;i != key ;i--)
        {
            list->data[i+1] = list->data[i];
        }
        list->data[key] = value;
        list->length++;
        return 1;
    }
    return 0;
}

//删除key 位置元素
bool list_delete(seq_list * list,int key)
{
    int i;
    if (-1 < key && key<list->length)
    {
        for(i=key;i<list->length;i++)
        {
            list->data[i] = list->data[i+1];
        }
        list->length--;

        return 1;
    }

    return 0;
}

//追加元素
bool list_append(seq_list *list,int value)
{
    if(list->length < SIZE)
    {
        list->data[list->length] = value;
        list->length++;
        return 1;
    }
    return 0;
}

bool list_pop(seq_list *list)
{
    if (list->length != 0)
    {
        list->length--;
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    cout << "----------无情的分割线--------" << endl;
    cout << "          ypb                " << endl;
    cout << "----------无情的copy---------" << endl;

    cout << endl;

    seq_list * list;

    init_list(list);

 
    return 0;
}
