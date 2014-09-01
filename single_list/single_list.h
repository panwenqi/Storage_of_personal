#ifndef SINGLE_LIST_H_
#define SINGLE_LIST_H_

typedef int Type;

typedef struct Node
{
	Type data;
	struct Node* next;
} Node;

typedef Node* PNode;

PNode create_node(Type p_data); //����������Ľ��

PNode init_slist();   //��ʼ�������������ص������ͷ���

PNode return_tail(PNode s_head);  //���������β��㣬һ��Ҫ�ڳ�ʼ���������������������

int slist_size(PNode s_head);  //������ĳ���

void insert_h_slist(PNode s_head, PNode s_tail, Type p_data);  //ͷ�巨���뵥����

void show_slist(PNode s_head);  //��ӡ������

void free_slist(PNode s_head);  //�ͷŵ�����
#endif