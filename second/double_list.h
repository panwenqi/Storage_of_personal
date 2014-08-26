#ifndef DOUBLE_LIST_H_
#define DOUBLE_LIST_H_
#include <stdlib.h>
#include <stdio.h>
typedef int Type;
typedef struct Node
{
	struct Node* front;  //链表的前驱
	struct Node* next;   //链表的后继
	Type data;           //链表的数据域
}Node;
typedef Node* PNode;

PNode create_node(Type p_data);  //创建一个节点

PNode init_dlist();  //初始化一个双链表，并且返回链表的头指针

PNode return_tail(PNode dl_head);  //返回链表的尾节点，注意，初始化一个链表后，应立即调用这个函数返回尾节点

int dlist_size(PNode dl_head);  //返回双链表的长度

void insert_h_node(PNode dl_head, PNode dl_tail, Type p_data);  //头插法插入链表

void insert_t_node(PNode dl_head, PNode dl_tail, Type p_data);  //尾插法插入链表

void show_dlist(PNode dl_head);  //打印双链表

void free_dlist(PNode dl_head);  //释放双链表
#endif