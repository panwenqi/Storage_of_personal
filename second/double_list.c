#include "double_list.h"
PNode create_node(Type p_data)
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

PNode init_dlist()
{
	PNode head = create_node(0);  //创建头节点
	PNode tail = create_node(0);  //创建尾节点
	if ((head != NULL) && (tail != NULL))
	{
		head->next = tail;
		tail->front = head;
	}
	return head;  //返回头节点
}

PNode return_tail(PNode dl_head)
{
	return (dl_head->next);
}

int dlist_size(PNode dl_head)
{
	int dl_size = 0;
	PNode temp = dl_head->next;  //注意了把头节点跳过去，从链表真正的第一个节点开始
	while ((temp->next) != NULL) //尾节点的next是null，所以尾节点不会加到链表的长度中
	{
		dl_size = dl_size + 1;
		temp = temp->next;
	}
	return dl_size;
}

void insert_h_node(PNode dl_head, PNode dl_tail, Type p_data)
{
	PNode temp = create_node(p_data);
	int dl_size = dlist_size(dl_head);
	if (temp != NULL)
	{
		if (dl_size == 0)  //双链表为空
		{
			temp->front = dl_head;
			temp->next = dl_tail;
			dl_head->next = temp;
			dl_tail->front = temp;
		}else{
			temp->next = dl_head->next;
			temp->front = dl_head;
			(dl_head->next)->front = temp;
			dl_head->next = temp;
		}
	}
}

void insert_t_node(PNode dl_head, PNode dl_tail, Type p_data)
{
	PNode temp = create_node(p_data);
	int dl_size = dlist_size(dl_head);
	if (temp != NULL)
	{
		if (dl_size == 0)
		{
			temp->front = dl_head;
			temp->next = dl_tail;
			dl_head->next = temp;
			dl_tail->front = temp;
		}else{
			temp->next = dl_tail;
			temp->front = dl_tail->front;
			(dl_tail->front)->next = temp;
			dl_tail->front = temp;
		}
	}
}

void show_dlist(PNode dl_head)
{
	PNode temp = dl_head->next;  //同样从头节点的下一个节点开始
	while((temp->next) != NULL)  //尾节点的next是null，也不会算上去
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void free_dlist(PNode dl_head)
{
	PNode p_now = dl_head;
	PNode p_next;
	while((p_now->next) != NULL)
	{
		p_next = p_now->next;
		free(p_now);
		p_now = p_next;
	}
	free(p_now);  //注意了尾节点没有释放，必须在这个地方进行释放
}