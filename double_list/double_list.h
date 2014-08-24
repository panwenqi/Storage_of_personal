#ifndef DOUBLE_LIST_H_
#define DOUBLE_LIST_H_

typedef int Type;  //�������ǽ��data���ֵ��������ͣ������Ժ��޸�

typedef struct Node //����һ��Node���͵Ľṹ�壬Ҳ��������˫����Ľ��
{
	struct Node *front;  //˫�����ǰ��
	struct Node *next;   //˫����ĺ��
	Type data;           //˫�����������
} Node;

typedef Node* PNode;   //����һ��ָ�������͵�ָ��

PNode create_node(Type p_data);  //������һ���½��ĺ���

PNode init_dlist();    //��ʼ��һ��˫��������������ͷ���

int list_size(PNode head); //��������ĳ���

void insert_h_list(PNode head, PNode tail, int p_data);  //ͷ�巨����һ�����

void show_list(PNode head);  //��ӡ����

void free_list(PNode head);  //�ͷ�����

PNode return_tail(PNode head);  //���������β���
#endif