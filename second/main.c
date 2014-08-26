#include "double_list.h"
int main()
{
	PNode head = init_dlist();
	PNode tail = return_tail(head);
	insert_h_node(head, tail, 1);
	insert_h_node(head, tail, 2);
	insert_t_node(head, tail, 3);
	show_dlist(head);
	free_dlist(head);

	system("pause");
	return 0;
}