#include <stdlib.h>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <regex>
#include <malloc.h>

using namespace std;

typedef char LType;

typedef struct LinkNode
{
    //数据域
    LType data;
    //指针域
    struct LinkNode* next;
}LinkNode;

LinkNode *head;

#define Test_Header printf("\n-----%s-----\n",__FUNCTION__);

//初始化函数
void linklistInit(LinkNode **head)
{
    *head = NULL;
}

//创建新节点函数
LinkNode *CreateNode(LType value)
{
    //为新节点申请空间
    LinkNode *new_node = (LinkNode*)malloc(sizeof(LinkNode));
    //给新节点赋值
    new_node->data = value;
    //将新节点的next指向空
    new_node->next = NULL;
    return new_node;
}
//销毁一个节点
void DestroyNode(LinkNode *node)
{
    free(node);
}
//顺序打印链表元素
void linklistPrint(LinkNode *head)
{
    if(head == NULL)
    {
        //空链表无需打印
        return;
    }
    LinkNode *cur = head;
    //遍历链表
    while(cur != NULL)
    {
        //打印元素和其对应的地址
        printf("%c|%p\n",cur->data,cur);
        //移动cur,以达到遍历链表的目的
        cur = cur->next;
    }
    printf("\n\n");
}
//逆序打印链表（递归思想）
void linklistReversePrint(LinkNode *head)
{
    if(head == NULL)
    {
        //空链表无需打印，也是递归的出口
        return;
    }   
    linklistReversePrint(head->next);
    printf("%c|%p ",head->data,head);
    printf("\n");
}
//尾插函数
LinkNode *linklistPushBack(LinkNode **head,LType value)
{
    //非法输入
    if(head == NULL)
    {
        return NULL;
    }
    //空链表
    if(*head == NULL)
    {
        //直接创建一个新的节点完成元素插入
        *head = CreateNode(value);
        return NULL;
    }
    else
    {
        LinkNode *cur = *head;
        //遍历链表，让cur指向最后一个元素
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        //创建一个新节点
        LinkNode *new_node = CreateNode(value);
        //将最后一个元素的next指向新节点
        cur->next = new_node;
        return new_node;
    }
}
//尾删函数
void linklistPopBack(LinkNode **head)
{
    //非法输入
    if(head == NULL)
    {
        return;
    }
    //空链表没有可删除的元素
    if(*head == NULL)
    {
        return;
    }
    //只有一个元素
    if((*head)->next == NULL)
    {
        //直接删除节点
        DestroyNode(*head);
        //将头结点置空
        *head = NULL;
        return;
    }
    else
    {
        LinkNode *cur = *head;
        //遍历链表，使cur指向倒数第二个元素
        while(cur->next->next != NULL)
        {
            cur = cur->next;
        }
        //创建指针指向最后一个元素，即我们需要删除的元素
        LinkNode *to_delete = cur->next;
        //将该节点销毁
        DestroyNode(to_delete);
        //将倒数第二个元素的next指向空
        cur->next = NULL;
    }
    return;
}
//头插函数
void linklistPushFront(LinkNode **head,LType value)
{
    //非法输入
    if(head == NULL)
    {
        return;
    }
    //空链表
    if(*head == NULL)
    {
        //直接创建一个新节点完成插入
        *head = CreateNode(value);
        return;
    }
    else
    {
        //创建一个新的指针指向头结点
        LinkNode *new_node = *head;
        //创建一个新的头结点
        *head = CreateNode(value);
        //将新的头结点的next指向旧的头结点
        (*head)->next = new_node;
    }
    return;
}
//头删函数
void linklistPopFront(LinkNode **head)
{
    //非法输入
    if(head == NULL)
    {
        return;
    }
    //空链表没有可删除的元素
    if(*head == NULL)
    {
        return;
    }
    else
    {
        //创建一个新的指针指向第二个元素
        LinkNode *new_node = (*head)->next;
        //将头结点的next指向空
        (*head)->next = NULL;
        //删除该头结点
        DestroyNode(*head);
        //将第二个元素设置成新的头结点
        *head = new_node;
    }
    return;
}
//查找链表中指定元素的地址
LinkNode *linklistFind(LinkNode *head,LType to_find)
{
    int count = 0;
    LinkNode *find = head;
    //空链表
    if(head == NULL)
    {
        return NULL;
    }
    else
    {
        //循环遍历链表
        for(;find->next != NULL;find = find->next)
        {
            if(find->data == to_find)
            {
                count++;
                //找到了返回该元素的地址
                return find;
            }
        }
    }
    //如果count计数为0，说明没有链表中不存在想要查找的元素
    if(count == 0)
    {
        printf("this value is non-existence\n");
    }
    //没找到返回空
    return NULL;
}

//在指定位置之前插入指定元素（遍历）函数
//时间复杂度为O(n)
void linklistInsertBefore(LinkNode **head,LinkNode *pos,LType value)
{
    //非法输入
    if(head == NULL)
    {
        return;
    }
    //空链表
    if(*head == NULL)
    {
        //直接创建一个新的节点
        *head = CreateNode(value);
        return;
    }
    //如果是头结点位置
    if(pos == *head)
    {
        //则进行头插
        linklistPushFront(head,value);
        return;
    }
    //如果为空
    if(pos == NULL)
    {
        //则进行尾插
        linklistPushBack(head,value);
        return;
    }
    else
    {
        LinkNode *cur = *head;
        //遍历链表
        while(cur->next != NULL)
        {
            //cur的下一个位置就是pos
            if(cur->next == pos)
            {
                //创建一个指针，以value值创建节点
                LinkNode *pre = CreateNode(value);
                //将cur的next修改指向新的节点的位置
                cur->next = pre;
                //将新节点的next指向pos，就在pos位置之前插入了新元素
                pre->next = pos;
                return;
            }
            //将cur移向下一个元素，以达到遍历链表的目的   
            cur = cur->next;
        }
    }
}
//在指定位置之前插入指定元素（不遍历）函数
//时间复杂度为O(1)
void linklistInsertBefore1(LinkNode **head,LinkNode *pos,LType value)
{
    //非法输入
    if(head == NULL)
    {
        return;
    }
    //空链表
    if(*head == NULL)
    {
        //直接创建一个新的节点
        *head = CreateNode(value);
        return;
    }
    //如果是头结点位置
    if(pos == *head)
    {
        //则进行头插
        linklistPushFront(head,value);
        return;
    }
    //如果位置为空
    if(pos == NULL)
    {
        //则进行尾插
        linklistPushBack(head,value);
        return;
    }
    else
    {
        //定义一个新指针指向pos的下一个位置
        LinkNode *cur = pos->next;
        //用pos位置的值创建一个新的节点
        LinkNode *new_node = CreateNode(pos->data);
        //将pos位置的值修改为value
        pos->data = value;
        //将pos的next指向新的节点
        pos->next = new_node;
        //将新节点的next指向pos的next，即指向cur
        new_node->next = cur;
    }
}
//在指定位置之后插入指定元素
void linklistInsertAfter(LinkNode **head,LinkNode *pos,LType value)
{
    //非法输入
    if(head ==NULL)
    {
        return;
    }
    //空链表
    if((*head) == NULL)
    {
        //直接以value值创建一个头结点
        *head = CreateNode(value);
        return;
    }
    //如果pos位置为空
    if(pos == NULL)
    {
        //则进行尾插
        linklistPushBack(head,value);
        return;
    }
    //如果pos为头结点的位置
    if(pos == *head)
    {
        //则进行头插
        linklistPushFront(head,value);
        return;
    }
    else
    {
        //创建一个新的指针指向头结点
        LinkNode *cur = *head;
        //遍历链表
        while(cur->next != NULL)
        {
            //cur的下一个位置就是pos
            if(cur->next == pos)
            {
                //以value值创建一个新的节点
                LinkNode *new_node = CreateNode(value);
                //新节点的next指向pos位置的next
                new_node->next = pos->next;
                //pos的next修改指向新的节点
                pos->next = new_node;
            }
            //移动cur
            cur = cur->next;
        }
    }
}
//删除指定位置的元素（遍历）函数
//时间复杂度为O（n）
void linklistErase(LinkNode **head,LinkNode *pos)
{
    //非法输入
    if(head == NULL)
    {
        return;
    }
    //空链表
    if(*head == NULL)
    {
        return;
    }
    //如果pos位置为空
    if(pos == NULL)
    {
        //则进行尾删
        linklistPopBack(head);
        return;
    }
    //如果pos为头结点的位置
    if(pos == *head)
    {
        //则进行头删
        linklistPopFront(head);
        return;
    }
    else
    {
        //创建新的指针指向头结点
        LinkNode *cur = *head;
        //遍历链表，遍历完成以后cur的下一个位置就是pos
        while(cur->next != pos)
        {
            cur = cur->next;
        }
        //将cur的next指向pos的next
        cur->next = pos->next;
        //销毁pos节点
        DestroyNode(pos);
    }
}
////删除指定位置的元素（遍历）函数
//时间复杂度为O(1)
void linklistErase2(LinkNode **head,LinkNode *pos)
{
    //非法输入
    if(head == NULL)
    {
        return;
    }
    //空链表无法删除
    if(*head == NULL)
    {
        return;
    }
    //如果pos位置为空
    if(pos == NULL)
    {
        //则进行尾删
        linklistPopBack(head);
        return;
    }
    //如果pos为头结点位置
    if(pos == *head)
    {
        //则进行头删
        linklistPopFront(head);
        return;
    }
    else
    {
        //创建一个新的指针指向pos的next
        LinkNode *to_delete = pos->next;
        //将pos的下一个位置的元素赋给pos
        pos->data = to_delete->data;
        //再将pos的next指向其下一个元素的next
        pos->next = to_delete->next;
        //将pos的下一个位置节点删除
        DestroyNode(to_delete);
    }
}
//删除指定元素，若存在多个元素则只删除第一个函数
void linklistRemove(LinkNode **head,LType to_delete)
{
    //非法输入
    if(head == NULL)
    {
        return;
    }
    //空链表没有可删除的元素
    if(*head == NULL)
    {
        return;
    }
    //如果头结点的元素是要删除的元素
    if((*head)->data == to_delete)
    {
        //则进行头删
        linklistPopFront(head);
        return;
    }
    LinkNode *cur = *head;
    //遍历链表
    while(cur != NULL && cur->next != NULL)
    {
        //要删除的元素是cur的下一个元素
        if(cur->next->data == to_delete)
        {
            //定义一个新的指针指向cur的下一个元素（待删除元素）的位置
            LinkNode *to_remove = cur->next;
            //将cur的next指向其下一个元素（待删除元素）的下一个位置
            cur->next = to_remove->next;
            //删除新的节点（即一开始定义的指向待删除元素的指针）
            DestroyNode(to_remove);
            return;
        }
        cur = cur->next;
    }
}
//判断链表是否为空链表
int linklistEmpty(LinkNode *head)
{
    //为空返回0否则返回1
    return head == NULL?0:1;
}
//求链表中元素个数，返回元素个数
size_t linklistSize(LinkNode *head)
{
    //空链表返回0
    if(head == NULL)
    {
        return 0;
    }
    size_t count = 0;
    LinkNode *cur = head;
    //遍历链表
    for(;cur != NULL;cur = cur->next)
    {
        count++;
    }
    return count;
}

//尾插的测试函数
void TestPushBack()
{
    Test_Header;
    //初始化链表
    linklistInit(&head);
    //尾插a b c d
    linklistPushBack(&head,'a');
    linklistPushBack(&head,'b');
    linklistPushBack(&head,'c');
    linklistPushBack(&head,'d');
    linklistPrint(head);
}
//尾删的测试函数
void TestPopBack()
{
    Test_Header;
    //尾删3次
    linklistPopBack(&head);
    linklistPopBack(&head);
    linklistPopBack(&head);
    linklistPrint(head);
}
//头插的测试函数
void TestPushFront()
{
    Test_Header;
    //头插b c d
    linklistPushFront(&head,'b');
    linklistPushFront(&head,'c');
    linklistPushFront(&head,'d');
    linklistPrint(head);
}
//头删的测试函数
void TestPopFront()
{
    Test_Header;
    //头删3次
    linklistPopFront(&head);
    linklistPopFront(&head);
    linklistPopFront(&head);
    linklistPrint(head);
}


int main(int argc, char *argv[])
{
    cout << "----------无情的分割线--------" << endl;
    cout << "          ypb                " << endl;
    cout << "----------无情的copy---------" << endl;

    cout << endl;



 
    return 0;
}
