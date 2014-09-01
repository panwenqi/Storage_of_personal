#include "single_list.h"
#include <stdlib.h>
#include <stdio.h>
PNode create_node(Type p_data)
{
	PNode temp = (PNode)malloc(sizeof(Node));
	if (temp != NULL)
	{
		temp->data = p_data;
		temp->next = NULL;
	}
	return temp;
}

PNode init_slist()
{
	PNode head = create_node(0);
	PNode tail = create_node(0);
	if ((head != NULL) && (tail != NULL))
	{
		head->next = tail;
	}
	return head;
}

PNode return_tail(PNode s_head)
{
	return (s_head->next);
//	return tail;
}

int slist_size(PNode s_head)
{
	PNode temp = s_head->next;   //把头结点跳过去
	int size = 0;
	while ((temp->next) != NULL)
	{
		size = size + 1;
		temp = temp->next;
	}
	return size;
}

void insert_h_slist(PNode s_head, PNode s_tail, Type p_data)
{
	PNode temp = create_node(p_data);
	int s_size = slist_size(s_head);
	if (temp != NULL)
	{
		if (s_size == 0)
		{
			temp->next = s_tail;
			s_head->next = temp;
		}else{
			temp->next = s_head->next;
			s_head->next = temp;
		}
	}
}

void show_slist(PNode s_head)
{
	PNode temp = s_head->next;  //把头结点跳过去
	while ((temp->next) != NULL)  //尾结点的next指针为NULL，尾结点不会被遍历
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void free_slist(PNode s_head)
{
	PNode p_now = s_head;
	PNode p_next = 0;
	while ((p_now->next) != NULL)
	{
		p_next = p_now->next;
		free(p_now);
		p_now = p_next;
	}
	free(p_now);
}

