#ifndef SINGLE_LIST_H_
#define SINGLE_LIST_H_

typedef int Type;

typedef struct Node
{
	Type data;
	struct Node* next;
} Node;

typedef Node* PNode;

PNode create_node(Type p_data); //创建单链表的结点

PNode init_slist();   //初始化单链表，并返回单链表的头结点

PNode return_tail(PNode s_head);  //返回链表的尾结点，一定要在初始化结点后立即调用这个函数

int slist_size(PNode s_head);  //求单链表的长度

void insert_h_slist(PNode s_head, PNode s_tail, Type p_data);  //头插法插入单链表

void insert_t_slist(PNode s_head, PNode s_tail, Type p_data);  //尾插法插入单链表

void insert_d_slist(PNode s_head, PNode s_tail, Type s_data, Type p_data);  //在链表中s_data结点后插入一个结点p_data

void delete_node(PNode s_head, PNode s_tail, Type p_data);  //删除一个数据域为p_data的结点

void show_slist(PNode s_head);  //打印单链表

void free_slist(PNode s_head);  //释放单链表
#endif