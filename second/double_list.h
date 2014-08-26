#ifndef DOUBLE_LIST_H_
#define DOUBLE_LIST_H_
#include <stdlib.h>
#include <stdio.h>
typedef int Type;
typedef struct Node
{
	struct Node* front;  //�����ǰ��
	struct Node* next;   //����ĺ��
	Type data;           //�����������
}Node;
typedef Node* PNode;

PNode create_node(Type p_data);  //����һ���ڵ�

PNode init_dlist();  //��ʼ��һ��˫�������ҷ��������ͷָ��

PNode return_tail(PNode dl_head);  //���������β�ڵ㣬ע�⣬��ʼ��һ�������Ӧ�������������������β�ڵ�

int dlist_size(PNode dl_head);  //����˫����ĳ���

void insert_h_node(PNode dl_head, PNode dl_tail, Type p_data);  //ͷ�巨��������

void insert_t_node(PNode dl_head, PNode dl_tail, Type p_data);  //β�巨��������

void show_dlist(PNode dl_head);  //��ӡ˫����

void free_dlist(PNode dl_head);  //�ͷ�˫����
#endif