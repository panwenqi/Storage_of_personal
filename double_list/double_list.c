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
	if ((head != NULL) && (tail != NULL))  //初始化就是把头结点指向尾结点，尾结点指向头结点
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
	int dl_size = dlist_size(dl_head);  //取得链表的长度，下面分空链表和非空链表两种情况
	if (temp != NULL)
	{
		if (dl_size == 0)  //双链表为空
		{
			temp->front = dl_head;
			temp->next = dl_tail;
			dl_head->next = temp;
			dl_tail->front = temp;
		}else{   //双链表不为空
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
	int dl_size = dlist_size(dl_head);  //取得链表的长度，下面插入的时候要分空链表和非空链表两种情况
	if (temp != NULL)
	{
		if (dl_size == 0)   //空链表
		{
			temp->front = dl_head;
			temp->next = dl_tail;
			dl_head->next = temp;
			dl_tail->front = temp;
		}else{   //非空链表
			temp->next = dl_tail;
			temp->front = dl_tail->front;
			(dl_tail->front)->next = temp;
			dl_tail->front = temp;
		}
	}
}
void insert_d_node(PNode dl_head, PNode dl_tail, Type dl_data, Type p_data)
{
	int m_flag = 0;  //此标志是标志链表中有没有dl_data,若是有的话，就置为1，没有就置为0
	PNode flag = dl_head->next;  //把头结点跳过去，防止插入的数据就是0，和头结点的数据域刚好相等
	while ((flag->next) != NULL)  //尾结点不会进入此循环，因为尾结点的next是NULL
	{
		if((flag->data) == dl_data)
		{
			PNode temp = create_node(p_data);
			if(temp != NULL)
			{
				temp->front = flag;
				temp->next = flag->next;
				(flag->next)->front = temp;
				flag->next = temp;
				m_flag++;
			}
		}
		flag = flag->next;
	}
	if (m_flag == 0)  //链表中没有dl_data
	{
		printf("not %d ! \n", dl_data);
	}
}

void delete_node(PNode dl_head, Type dl_data)
{
	PNode temp = dl_head->next;  //把头结点跳过去，防止插入的数据就是0，和头结点的数据域刚好相等
	PNode p_next;
	int flag = 0;   //标志位，标志链表中是否有dl_data
	while ((temp->next) != NULL)  //尾结点不会进入此循环，因为尾结点的next是NULL
	{
		p_next = temp->next;  //注意这种思想
		if ((temp->data) == dl_data)
		{
			(temp->front)->next = temp->next;
			(temp->next)->front = temp->next;
			flag++;
			free(temp);
		}
		temp = p_next;   //注意这种思想
	}
	if (flag == 0)  //链表中没有dl_data，没法删除
	{
		printf("nothing %d \n", dl_data);
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
	PNode p_now = dl_head;  //注意此时是释放整个链表，头结点和尾结点都要释放，所以从头结点
	PNode p_next;
	while((p_now->next) != NULL)  //此时尾结点不会释放，尾结点的next是NULL，不会进入此循环
	{
		p_next = p_now->next;
		free(p_now);
		p_now = p_next;
	}
	free(p_now);  //注意了尾节点没有释放，必须在这个地方进行释放
}