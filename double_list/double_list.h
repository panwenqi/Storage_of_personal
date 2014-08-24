#ifndef DOUBLE_LIST_H_
#define DOUBLE_LIST_H_

typedef int Type;  //定义我们结点data部分的数据类型，方便以后修改

typedef struct Node //定义一个Node类型的结构体，也就是我们双链表的结点
{
	struct Node *front;  //双链表的前驱
	struct Node *next;   //双链表的后继
	Type data;           //双链表的数据域
} Node;

typedef Node* PNode;   //定义一个指向结点类型的指针

PNode create_node(Type p_data);  //创建接一个新结点的函数

PNode init_dlist();    //初始化一个双链表，并返回他的头结点

int list_size(PNode head); //返回链表的长度

void insert_h_list(PNode head, PNode tail, int p_data);  //头插法插入一个结点

void show_list(PNode head);  //打印链表

void free_list(PNode head);  //释放链表

PNode return_tail(PNode head);  //返回链表的尾结点
#endif