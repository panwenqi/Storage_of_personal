#include "double_list.h"
#include <stdio.h>
#include <stdlib.h>
PNode create_node(Type p_data)  //创建一个结点
{
	PNode temp = (PNode)malloc(sizeof(Node));
	printf("%p\n", &temp);
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
	if (temp != NULL) //此处有问题，尾节点的next居然指向了上一个节点
	{
		if (size == NULL)
		{
			temp->front = tail->front;

			/* 注意了，这个疑问点终于解决了，你malloc产生的结点，其实本质就是把malloc申请的那段内存的起始地址给了temp
			   也就是说tail就是代表着尾结点的那段内存起始值，head->next 也是尾结点的内存起始地址
			   tail也是代表着尾结点的起始地址，使用这两个都行
			   又说明了一个东西：指针的值就是一个地址，指针本身是一个变量，这个变量也有他自己的地址，但是和他里面存放的数据（地址）
			   不是同一个地址
			*/

//			temp->next = head->next; //下面的也可以
			temp->next = tail;  //上面的也可以
			head->next = temp;
			tail->front = temp;
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
	p = p->next;
	while ((p->data) != NULL)
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