#include "double_list.h"
#include <stdio.h>
#include <stdlib.h>
PNode create_node(Type p_data)  //创建一个结点
{
	PNode temp = (PNode)malloc(sizeof(Node));
	if (temp != NULL)
	{
		temp->front = NULL;
		temp->next = NULL;
		temp->data = p_data;
	}
	return temp;
}

PNode init_dlist()  //初始化一个双链表
{
	PNode head = create_node(0);  //创建双链表的头结点
	PNode tail = create_node(0);  //创建双链表的尾结点
	if ((head != NULL) && (tail != NULL))
	{
		head->next = tail;
		tail->front = head;
	}
	return head;
}

PNode return_tail(PNode head)
{
	return head->next; 
}

int list_size(PNode head)  //返回链表的长度
{
	int n = 0;
	PNode position = head;
	position = position->next;
	if ((position->data) != 0)
	{
		position = position->next;
		n = n + 1;
	}
	return n;
}

void insert_h_list(PNode head, PNode tail, Type p_data)  //头插法
{
	PNode temp = create_node(p_data);
	int size = list_size(head);
	if (temp != NULL)
	{
		if (size == NULL)
		{
			temp->front = tail->next;
			temp->next = head->next;
			head->next = temp;
			tail->next = temp;
		}else
		{
			temp->front = head;
			temp->next = head->next;
			(head->next)->front = temp;
			head->next = temp;
		}
	}
}

void show_list(PNode head)
{
	PNode p = head;
	while ((p->next) != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

void free_list(PNode head)
{
	PNode p_now = head;
	PNode p_next = 0;
	while ((p_now->next) != NULL)
	{
		p_next = p_now->next;
		free(p_now);
		p_now = p_next;
	}
}