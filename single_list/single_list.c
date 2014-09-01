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

void insert_t_slist(PNode s_head, PNode s_tail, Type p_data)
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
			int i = 0;
			PNode p_now = s_head->next;   //头结点跳过去，尾结点不影响任何东西(只有在算长度的时候才能影响结果)
			for (i = 0; i < s_size; i++)  //效率不高，不建议采用尾结点插入法
			{
				if (i == s_size-1)
				{
					p_now->next = temp;
					temp->next = s_tail;
				}
				p_now = p_now->next;
			}
		}
	}
}

void insert_d_slist(PNode s_head, PNode s_tail, Type s_data, Type p_data)
{
	PNode p_now = 0;
	PNode temp = create_node(p_data);
	if (temp == NULL)
	{
		return;
	}
	p_now = s_head->next;   //依然还是跳过头结点，尾结点的next指针就是null，不用考虑
	while ((p_now->next) != NULL)
	{
		if ((p_now->data) == s_data)
		{
			temp->next = p_now->next;
			p_now->next = temp;
		}
		p_now = p_now->next;
	}
}

void delete_node(PNode s_head, PNode s_tail, Type p_data)
{
	PNode p_front = s_head;   //前一个结点
	PNode p_now = s_head->next;  //当前结点，也就是要比较数据域的结点，在这里，头结点依然还是跳过去，不过我们要头结点，这样第二次循环的时候能记录第一个("前一个")结点位置
	int s_size = slist_size(s_head);  //下一个结点
	/*  每一次比较，都会把这三个结点都往下移动一个
		依然还是把头结点跳过去，但是为了在第二次循环的时候能记录第一个结点，我们从头结点开始，实际比较的时候是从第一个结点开始的
	*/

	PNode p_next = p_now->next;
	while ((p_now->next) != NULL)
	{
		if ((p_now->data) == p_data)
		{
			p_front->next = p_next;
			free(p_now);
			p_now = p_next;
		}
		p_front = p_now;
		p_now = p_next;
		p_next = p_next->next;
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

