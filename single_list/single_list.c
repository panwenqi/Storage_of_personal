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
	PNode temp = s_head->next;   //��ͷ�������ȥ
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
			PNode p_now = s_head->next;   //ͷ�������ȥ��β��㲻Ӱ���κζ���(ֻ�����㳤�ȵ�ʱ�����Ӱ����)
			for (i = 0; i < s_size; i++)  //Ч�ʲ��ߣ����������β�����뷨
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
	p_now = s_head->next;   //��Ȼ��������ͷ��㣬β����nextָ�����null�����ÿ���
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
	PNode p_front = s_head;   //ǰһ�����
	PNode p_now = s_head->next;  //��ǰ��㣬Ҳ����Ҫ�Ƚ�������Ľ�㣬�����ͷ�����Ȼ��������ȥ����������Ҫͷ��㣬�����ڶ���ѭ����ʱ���ܼ�¼��һ��("ǰһ��")���λ��
	int s_size = slist_size(s_head);  //��һ�����
	/*  ÿһ�αȽϣ��������������㶼�����ƶ�һ��
		��Ȼ���ǰ�ͷ�������ȥ������Ϊ���ڵڶ���ѭ����ʱ���ܼ�¼��һ����㣬���Ǵ�ͷ��㿪ʼ��ʵ�ʱȽϵ�ʱ���Ǵӵ�һ����㿪ʼ��
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
	PNode temp = s_head->next;  //��ͷ�������ȥ
	while ((temp->next) != NULL)  //β����nextָ��ΪNULL��β��㲻�ᱻ����
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

